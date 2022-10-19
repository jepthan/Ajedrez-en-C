using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpFrontEnd.NewFolder
{
    internal class Controlador
    {
        TableroTiro table; 

        public Controlador()
        {
            table = new TableroTiro();
        }
        public void Dibujar(Graphics grafics)
        {
            table.Dibujar(grafics);
        }
    }
}
