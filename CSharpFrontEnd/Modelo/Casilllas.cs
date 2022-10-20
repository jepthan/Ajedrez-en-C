using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpFrontEnd.NewFolder
{
    public class Casilllas : Square
    {
        public Casilllas(int x, int y, Bitmap bmp) : base(x, y, bmp)
        {
           
            ///rectangulo = new Rectangle(this.x + 5, this.y + 5, this.width - 10, this.height - 10);
            //por la linea de codigo 16 paso mucho sufrimiento y dolor
        }
    }
}
