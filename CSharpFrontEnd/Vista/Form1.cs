using CSharpFrontEnd.Modelo;

namespace CSharpFrontEnd
{
    public partial class Form1 : Form
    {
        public int posx { get; set; }//pos x y y de caballo
        public int posy { get; set; }

        private Archivos movimientos;
        public Form1()
        {
            movimientos = new Archivos("input.txt");
            InitializeComponent();
            CustomComponents();
            posx = 0;
            posy = 0;
            this.SetStyle(ControlStyles.DoubleBuffer | ControlStyles.AllPaintingInWmPaint, true);
            this.UpdateStyles();

        }

        private void pictureBox1_Paint(object sender, System.Windows.Forms.PaintEventArgs e)
        {
            // Create a local version of the graphics object for the PictureBox.
            Graphics g = e.Graphics;

            controlador.Dibujar(g);
        }
        public void MovCaballoEvent(Object sender, KeyPressEventArgs e)
        {
            //EDebug.WriteLine("Moviendo el caballo");
            if (e.KeyChar == 'E' || e.KeyChar == 'e')
            {
                this.controlador.moveCaballo(posx, posy);

                posx = movimientos.getinput();
                posy = movimientos.getinput();
                /*if (posx < 7)
                {
                    posx++;
                }
                else
                {
                    posx = 0;
                    if (posy < 7)
                    {
                        posy++;
                    }
                    else
                    {
                        posy = 0;
                    }
                }*/
                this.Refresh();
            }
        }
    }
}
