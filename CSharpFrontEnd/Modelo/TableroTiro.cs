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
            casilla = new List<Casilllas>();
            for (int x=0; x<80; x++)
            {
                for (int y=0; y<80; y++)
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
                        casilla.Add(new Casilllas((black.Width * j)+20, (black.Height * i)+20, black));
                    }
                    else
                    {
                        casilla.Add(new Casilllas((white.Width * j)+20, (white.Height * i)+20, white));
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
                u.Dibujar(grafics);
            }
        }
    }
}
