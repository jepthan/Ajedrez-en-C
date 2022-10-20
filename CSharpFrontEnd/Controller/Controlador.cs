using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;
using CSharpFrontEnd.Modelo;
using CSharpFrontEnd.NewFolder;

namespace CSharpFrontEnd.Controller
{
    public class Controlador
    {
        public TableroTiro table { get; set; }

        public Caballo _caballo;

        public Controlador()
        {
            table = new TableroTiro();
            _caballo = new Caballo(0,0);
        }
        public void Dibujar(Graphics grafics)
        {
            table.Dibujar(grafics);
            _caballo.Dibujar(grafics);
        }

        public void moveCaballo(int x, int y)
        {
            int pos = x + y * 8;
            _caballo.moveToPos(table.casilla[pos]);
        }
    }
}
