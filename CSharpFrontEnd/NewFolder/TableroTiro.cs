using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpFrontEnd.NewFolder
{
    internal class TableroTiro
    {
        private String[,] matriz { get; set; }//matriz 
        private Bitmap black; //color negro
        private Bitmap white;//color blanco
        private List<Casilllas> casilla { get; set; }

        public TableroTiro()
        {
            this.black = new Bitmap(80,80);
            this.white = new Bitmap(80,80);

            for (int x=80; x<80; x++)
            {
                for (int y=80; y<80; y++)
                {
                    this.black.SetPixel(x,y, Color.Black);
                    this.white.SetPixel(x, y, Color.White);
                }
            }
            this.Iniciar();
        }
        private void Iniciar()
        {
            this.matriz = new String[8, 8];
            int cont = 0;
            Casilllas unit; //bendita sea mi dislexia lll

            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (cont % 2 == 0)
                    {
                        unit = new Casilllas(black.Width * j, black.Height * i, black);
                    }
                    else
                    {
                        unit = new Casilllas(white.Width * j, white.Height * i, white);
                    }
                   // this.matriz[i,j] = "*";
                   // unitBoards.Add(ub);
                    cont++;
                }
                cont++;
            }
        }
        public void Dibujar(Graphics grafics)
        {
            foreach (Casilllas u in casilla)
            {
                u.mover(grafics);
            }
        }
    }
}
