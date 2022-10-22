using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Reflection.PortableExecutable;
using System.Text;
using System.Threading.Tasks;

namespace CSharpFrontEnd.Modelo
{
    public class Archivos
    {
        private string filepath;
        private string dirPath;
        private StreamWriter fileWriter;
        private StreamReader fileReader;
        public Archivos(string _path)
        {
            filepath = _path;
            dirPath = "AppInfo\\";
            //revisa si el directorio existe
            if (!Directory.Exists(dirPath))
            {
                //si no existe crea uno
                Directory.CreateDirectory(dirPath);
            }

            string fullPath = dirPath + filepath;
            
            //si el archivo no existe lo crea
            if (!File.Exists(fullPath))
            {
                // crea el archivo y escribe en el 
                fileWriter = File.CreateText(fullPath);
            }



            // abre el archivo para leerlo
            fileReader = File.OpenText(fullPath);

        }
        public int getinput()
        {
            fileWriter.Dispose();
            if(fileReader == null)
            {
                string fullpath = dirPath + filepath;
                fileReader = File.OpenText(fullpath);
            }
            Debug.WriteLine(fileReader.ReadLine());
            

            return 0;
        }
        public void setOutput(int x, int y)
        {
            fileReader.Dispose();
            if (fileWriter == null)
            {
                string fullpath = dirPath + filepath;
                Debug.WriteLine("Creando archivo: " + fullpath);
                fileWriter = File.CreateText(fullpath);
            }
            
            Debug.WriteLine($"Escribiendo en archivo: X({x}) , y({y})");
            fileWriter.WriteLine(x);
            fileWriter.WriteLine(y);
            fileWriter?.Close();
        }
        
    }
}
