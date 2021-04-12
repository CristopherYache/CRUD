// Con_SQL.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include<mysql.h>
#include <iostream>
#include<string>

 
using namespace std;
int q_estado;

void select_productos();
void insert_productos();
void actualizar_marca();


int main() {
    select_productos();
    insert_productos();
    actualizar_marca();
}
void insert_productos()
{
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "root", "crud", 3309, NULL, 0);
    if (conectar)
    {

        cout << "color a";
        cout << "Conexion establecida"<<endl;

        string producto, descripcion, fecha_ingreso = "now()";
        string id_marca, existencia, precio_costo, precio_venta;
        
        cout << "\ningrese el producto: ";
        getline(cin, producto);
        cout << "\ningrese el id_marca: ";
        cin >> id_marca;
        cin.ignore();
        cout << "\ningrese la descripcion: ";
        getline(cin, descripcion);
        cout << "\ningrese el precio costo: ";
        cin >> precio_costo;
        cin.ignore();
        cout << "\ningrese el precio venta: ";
        cin >> precio_venta;
        cin.ignore();
        cout << "\ningrese las existencias: ";
        cin >> existencia;
        cout << "\nla fecha de ingreso será esta hora en la que se estan ingresando datos" << endl;

        string insert = "insert into productos(producto,id_marca,descripcion,precio_costo,precio_venta,existencia,fecha_ingreso) values ('" + producto + "' , " + id_marca + " , '" + descripcion + "' , " + precio_costo + "," + precio_venta + "," + existencia + "," + fecha_ingreso + ")";
        const char* i = insert.c_str();
        q_estado = mysql_query(conectar, i);
        if (!q_estado)
        {
            cout << "insert exitoso" << endl;
        }
        else
        {
            cout << "error en insert" << endl;
        }
    }
}

void select_productos()
{
    system("cls");
    MYSQL* conectar;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "empresa_tarea", "Empres@345", "db_empresa_tarea", 3306, NULL, 0);
    if (conectar) {
        string consulta = "Select * from productos";
        const char* c = consulta.c_str();
        q_estado = mysql_query(conectar, c);
        if (!q_estado) {
            resultado = mysql_store_result(conectar);
            while (fila = mysql_fetch_row(resultado)) {
                cout << fila[0] << "," << fila[1] << endl;
            }
        }
        else {
            cout << "Error en el select..." << endl;
        }
    }
}

void actualizar_marca() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "programer1", "db_crud", 0, NULL, 0);
    if (conectar) {
        int idaux, op = 0;

        while (op != 3) {
            menu_actualizar_marca();
            cout << "Opcion: ";
            cin >> op;

            if (op == 1) {
                string nid;
                cout << "Ingrese el id de la marca que quiere modificar: ";
                cin >> idaux;

                cout << "Ingrese el nuevo id: ";
                getline(cin, nid);
                cin.ignore();

                string update = "update marcas set (idmarca) values('" + nid + "') where idmarca = idaux ";
                const char* i = update.c_str();

                q_estado = mysql_query(conectar, i);
                if (!q_estado)
                {
                    cout << "Update exitoso . . ." << endl;
                }
                else
                {
                    cout << "Error en Update . . ." << endl;
                }
            }

            if (op == 2) {
                string nmarca;
                cout << "Ingrese el id de la marca que quiere modificar: ";
                cin >> idaux;

                cout << "Ingrese la nueva marca: ";
                cin >> nmarca;

                string update = "update marcas set marca='" + nmarca + "' where idmarca = idaux ";
                const char* i = update.c_str();

                q_estado = mysql_query(conectar, i);
                if (!q_estado)
                {
                    cout << "Update exitoso . . ." << endl;
                }
                else
                {
                    cout << "Error en Update . . ." << endl;
                }
            }

        }
    }
}
