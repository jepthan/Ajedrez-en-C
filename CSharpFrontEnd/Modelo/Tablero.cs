using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpFrontEnd.Modelo
{
    internal class Tablero
    {
        Casilla[,] casillas { get; set; }
        Caballo oCaballo { get; set; }

        Tablero()
        {
            casillas = new Casilla[8,8];
            oCaballo = new Caballo();
        }
    }
}
