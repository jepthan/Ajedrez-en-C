using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpFrontEnd.NewFolder
{
    public class Square
    {
        public int x { get; set; }
        public int y { get; set; }
        public int width { get; set;}
        public int height{ get; set;}
        protected Bitmap Imagen { get; set; }
        //protected Rectangle space { get; set; 

        public Square(int x, int y, Bitmap bmp)
        {
            this.x = x;
            this.y = y;
            this.Imagen = bmp;
            this.width = this.Imagen.Width;
            this.height = this.Imagen.Height;
        }

        public void Dibujar(Graphics graphics)
        {
            //space = new System.Drawing.Rectangle(0, 0, this.Width, this.Height);
            graphics.DrawImage(Imagen, x, y, width, height);
        }
    }
}
