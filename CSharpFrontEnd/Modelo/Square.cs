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
        public Square(int x, int y)
        {
            this.x = x;
            this.y = y;
            this.Imagen = null;
            this.width = 0;
            this.height = 0;
        }
        public void setImagen(Bitmap img)
        {
            this.Imagen = img;
            this.width = this.Imagen.Width;
            this.height = this.Imagen.Height;
        }

        public void Dibujar(Graphics graphics)
        {
            graphics.DrawImage(Imagen, x, y, width, height);
        }
    }
}
