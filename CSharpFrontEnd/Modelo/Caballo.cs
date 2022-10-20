using CSharpFrontEnd.NewFolder;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using static System.Net.Mime.MediaTypeNames;

namespace CSharpFrontEnd.Modelo
{
    public class Caballo : Square
    {
        private Bitmap imagen;
        public Caballo(int x, int y) : base(x, y)
        {
            var tempimg = new Bitmap("C:\\Users\\jefte\\Programacion\\Paradigmas\\Proyecto\\Proyecto_Paradigmas\\CSharpFrontEnd\\Images\\Caballo.png");
            
            
            //Scale Bitmap
            float width = 100;
            float height = 100;
            var brush = new SolidBrush(Color.Transparent);
            float scale = Math.Min(width / tempimg.Width, height / tempimg.Height);
            //imagen re escalada temporal
            var bmp = new Bitmap((int)width, (int)height);
            //graficos de imagen temporal
            var graph = Graphics.FromImage(bmp);

            var scaleWidth = (int)(tempimg.Width * scale);
            var scaleHeight = (int)(tempimg.Height * scale);
            //pintar imagen en bitmap de imagen temporal
            graph.FillRectangle(brush, new RectangleF(0, 0, width, height));
            graph.DrawImage(tempimg, ((int)width - scaleWidth) / 2, ((int)height - scaleHeight) / 2, scaleWidth, scaleHeight);

            this.imagen = bmp;

            base.setImagen(this.imagen);
        }
        
        public void moveToPos(Casilllas casilla)
        {
            this.x = casilla.x - 15;
            this.y = casilla.y - 10;
        }
        
    }
}
