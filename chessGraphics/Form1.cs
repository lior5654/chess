using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;
using System.Media; //  for play sound


namespace chessGraphics
{
    public partial class Form1 : Form
    {
        private SoundPlayer gameSong;
        private Square srcSquare;
        private Square dstSquare;

        private pipe enginePipe;
        Button[,] matBoard;

        bool isCurPlWhite = true;
        bool isGameOver = false;

        const int BOARD_SIZE = 8;

        public Form1()
        {
            InitializeComponent();


            



            //SecondaryBuffer buffer = new SecondaryBuffer(Properties.Resources.game_song, device);
            //
            //buffer.Play(0, BufferPlayFlags.Looping);
            //new System.Threading.Thread(() => {
            //    gameSong = new SoundPlayer(Properties.Resources.game_song);
            //    gameSong.PlayLooping();
            //}).Start();

        }

        private void initForm()
        {
            enginePipe.connect();

            Invoke((MethodInvoker)delegate {  

                lblWaiting.Visible = false;
                lblCurrentPlayer.Visible = true;
                label1.Visible = true;

                        

                string s = enginePipe.getEngineMessage();

                if (s.Length != (BOARD_SIZE * BOARD_SIZE + 1))
                {
                    MessageBox.Show("The length of the board's string is not according the PROTOCOL");
                    this.Close();

                }
                else
                {
                    isCurPlWhite = (s[s.Length - 1] == '0');
                    paintBoard(s);
                }

            });
    
        }

        Thread connectionThread;
        private void Form1_Load(object sender, EventArgs e)
        {
            enginePipe = new pipe();
            //this.Show();
            
            //MessageBox.Show("Press OK to start waiting for engine to connect...");
            connectionThread = new Thread(initForm);
            connectionThread.Start();
            connectionThread.IsBackground = true;
            
            //initForm();
        
        }

        Image getImageBySign(char sign)
        {
            switch (sign)
            {
                case 'q':
                    return Properties.Resources.q_black;
                case 'Q':
                    return Properties.Resources.q_white;
                case 'k':
                    return Properties.Resources.k_black;
                case 'K':
                    return Properties.Resources.k_white;
                case 'p':
                    return Properties.Resources.p_black;
                case 'P':
                    return Properties.Resources.p_white;
                case 'r':
                    return Properties.Resources.r_black;
                case 'R':
                    return Properties.Resources.r_white;
                case 'n':
                    return Properties.Resources.n_black;
                case 'N':
                    return Properties.Resources.n_white;
                case 'b':
                    return Properties.Resources.b_black;
                case 'B':
                    return Properties.Resources.b_white;
                case '#':
                    return null;
                default:
                    return Properties.Resources.x;

            }
        }

        private void paintBoard(string board)
        {
            int i, j, z=0;

            matBoard = new Button[BOARD_SIZE, BOARD_SIZE];

            btnBoard.FlatAppearance.MouseOverBackColor = Color.LightGray;
            
            Button newBtn;
            Point pnt;

            int currentWidth = btnBoard.Location.X;
            int currentHeight = btnBoard.Location.Y;
            
            bool isColBlack = true;
            bool isRowBlack = true ;
            
            this.SuspendLayout();

            lblCurrentPlayer.Text = isCurPlWhite ? "White" : "Black";

            for (i = 0; i < BOARD_SIZE; i++)
            {
                currentWidth = btnBoard.Location.X;
                isColBlack = isRowBlack;

                for (j = 0; j < BOARD_SIZE; j++)
                {
                    newBtn = new Button();
                    matBoard[i, j] = newBtn;

                    newBtn.FlatAppearance.MouseOverBackColor = btnBoard.FlatAppearance.MouseOverBackColor ;
                    newBtn.BackColor = isColBlack ? Color.Gray : Color.White;
                    newBtn.FlatAppearance.BorderColor = btnBoard.FlatAppearance.BorderColor;
                    newBtn.FlatAppearance.BorderSize = btnBoard.FlatAppearance.BorderSize;
                    newBtn.FlatStyle = btnBoard.FlatStyle;

                    newBtn.Size = new System.Drawing.Size(btnBoard.Width, btnBoard.Height);
                    newBtn.Tag = new Square(i, j);
                    pnt = new Point(currentWidth, currentHeight );
                    newBtn.Location = pnt;
                    newBtn.BackgroundImageLayout = ImageLayout.Stretch;

                    newBtn.BackgroundImage  = getImageBySign(board[z]);
                    
                    newBtn.Click += lastlbl_Click;

                    Controls.Add(newBtn);


                    currentWidth += btnBoard.Width;
                    isColBlack = !isColBlack;
                    z++;

                }

                isRowBlack = !isRowBlack;
                currentHeight += btnBoard.Height;

            }

            Controls.Remove(btnBoard);
            this.ResumeLayout(false);
        }

        void lastlbl_Click(object sender, EventArgs e)
        {
            Button b = (Button)sender;
            if (srcSquare != null)
            {
                // unselected
                if (matBoard[srcSquare.Row, srcSquare.Col] == b)
                {
                 
                    matBoard[srcSquare.Row, srcSquare.Col].FlatAppearance.BorderColor = Color.Blue;
                    srcSquare = null;
                }
                else
                {
                    dstSquare = (Square)b.Tag;
                    matBoard[dstSquare.Row, dstSquare.Col].FlatAppearance.BorderColor = Color.DarkGreen;

                    Thread t = new Thread(playMove);
                    t.Start();
                 //   t.IsBackground = true;
                    //playMove();
                }
            }
            else
            {
                srcSquare = (Square)b.Tag;
                matBoard[srcSquare.Row, srcSquare.Col].FlatAppearance.BorderColor = Color.DarkGreen;
            }
         
        }

        // messages should be according the protocol.
        // index is the message number in the protocol
        string[] messages =  {
            "Valid Move",
            "Valid Move, Chess!",
            "Invalid Move, Incorrect Player",
            "Invalid Move, Destination is not Free",
            "Invalid Move, Chess will Occur",
            "Invalid Move, Out of Bounds",
            "Invalid Move, Illegal Movement with Piece",
            "Invalid Move, Source and Dest are Equal",
            "Game over, CHECKMATE!",
            "Unknown message"
            };


        string convertEngineToText(string m)
        {
            int res;
            bool b = int.TryParse(m, out res);

            if (!b || res < 0 || res >= messages.Length)
                return messages[messages.Length - 1];

            return messages[res];
        }
        


        void playMove()
        {
            if (isGameOver)
                return;


            try
            {
                 Invoke((MethodInvoker)delegate {

                     lblEngineCalc.Visible = true;
            
                     lblMove.Text = string.Format("{0} -> {1}", srcSquare, dstSquare);
                    lblMove.Visible = true;
                    //lblEngineCalc.Invalidate();
            
                    label2.Visible = false;
                    lblResult.Visible = false;

                    this.Refresh();
            

                    // should send pipe to engine
                    enginePipe.sendEngineMove(srcSquare.ToString() + dstSquare.ToString());
                    

                     // should get pipe from engine
                    string m = enginePipe.getEngineMessage();

                    if (!enginePipe.isConnected())
                    {
                        MessageBox.Show("Connection to engine has lost. Bye bye.");
                        this.Close();
                        return;
                    }

                    string res = convertEngineToText(m);

                     if (res.ToLower().StartsWith("valid") || res.ToLower().StartsWith("game over"))
                     {
                         // move sound
                         
                         

                         isCurPlWhite = !isCurPlWhite;
                         lblCurrentPlayer.Text = isCurPlWhite ? "White" : "Black";

                         SoundPlayer snd;
                         // if have solder there
                         if (matBoard[dstSquare.Row, dstSquare.Col].BackgroundImage != null)
                         {
                             snd = new SoundPlayer(Properties.Resources.eat_soldier);
                         }
                         else
                         {
                             snd = new SoundPlayer(Properties.Resources.move_soldier);
                         }
                         snd.Play();
                         
                         // move solder
                         matBoard[dstSquare.Row, dstSquare.Col].BackgroundImage = matBoard[srcSquare.Row, srcSquare.Col].BackgroundImage;
                         // remove before
                         matBoard[srcSquare.Row, srcSquare.Col].BackgroundImage = null;

                         matBoard[srcSquare.Row, srcSquare.Col].FlatAppearance.BorderColor = Color.Blue;
                         matBoard[dstSquare.Row, dstSquare.Col].FlatAppearance.BorderColor = Color.Blue;
                     }
                     else
                     {

                         SoundPlayer snd = new SoundPlayer(Properties.Resources.invalid_move);
                         snd.Play();
                         // errore sound
                     }
                    lblEngineCalc.Visible = false;
                    lblResult.Text = string.Format("{0}", res);
                    lblResult.Visible = true;
                    label2.Visible = true;
                    this.Refresh();
                    // win or lose sound
                    if (res.ToLower().StartsWith("game over"))
                    {
                        isGameOver = true;
                        gameSong.Stop();
                        SoundPlayer sound = new SoundPlayer(Properties.Resources.win);
                        sound.Play();
                        MessageBox.Show(string.Format("{0} {1}",(isCurPlWhite ? "White" : "Black"),"is the winner!"));
                        this.Refresh();

                    }
                 });
                
           
                }
                catch
                {

                }
                finally
                {
                    Invoke((MethodInvoker)delegate
                    {
                        if (srcSquare != null)
                            matBoard[srcSquare.Row, srcSquare.Col].FlatAppearance.BorderColor = Color.Blue;

                        if (dstSquare != null)
                            matBoard[dstSquare.Row, dstSquare.Col].FlatAppearance.BorderColor = Color.Blue;

                        dstSquare = null;
                        srcSquare = null;

                    });
                }

        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
   

            enginePipe.sendEngineMove("quit");
            enginePipe.close();
        }
    }
}
