#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

struct TNodo{
    int info;
    TNodo *liga;
};

void listasCirculares();
void listasSimples();
void ejercicios();
TNodo *crea();
void quita(TNodo *aux);
void listasCirculares2(bool circ);

//Prototipos Listas simples
TNodo *insertaFinal(TNodo *p, int dato);
TNodo *insertaInicio(TNodo *p, int dato);
void recorre(TNodo *p);
TNodo *insertaAntes(TNodo *p, int dato, int ref);
TNodo *insertaDespues(TNodo *p, int dato, int ref);
TNodo *eliminaInicio(TNodo *p);
TNodo *eliminaRef(TNodo *p, int ref);
TNodo *eliminaFinal(TNodo *p);
TNodo *eliminaAntes(TNodo *p, int ref);
TNodo *eliminaDespues(TNodo *p, int ref);
TNodo *buscaRef(TNodo *p, int ref);

//Prototipos Listas Circulares

TNodo* insertaInicioCircular(TNodo *p, int dato);
TNodo* insertaFinalCircular(TNodo *p, int dato);
void recorreCircular(TNodo *p);
TNodo * insertaAntesCircular(TNodo *p, int dato,int ref);
TNodo* insertaDespuesCircular(TNodo *p, int dato, int ref);
TNodo *eliminaFinalCircular(TNodo *p);
TNodo *eliminaInicioCircular(TNodo *p);
TNodo *eliminaAntesCircular(TNodo *p,int ref);
TNodo *eliminaDespuesCircular(TNodo *p, int ref);
TNodo *eliminaReferenciaCircular(TNodo *p,int ref);


//Ejercicios
TNodo* generaListaAleatoria(TNodo *p);
void imprimirListaRecursiva(TNodo *p);
TNodo* ordenarLista(TNodo *p);
TNodo* mezclarListas(TNodo* lista1, TNodo* lista2);
TNodo* mezclarDescendenteRecursivo(TNodo* lista1, TNodo* lista2);
void dividirLista(TNodo* lista, TNodo*& listaPositivos, TNodo*& listaNegativos);
TNodo *buscaRefRecursiva(TNodo *p, int ref, int &cont);
TNodo* generaListaCircularAleatoria(TNodo *p);
bool buscar(TNodo *p, int ref);
TNodo *ordenaRecursivo(TNodo *p, TNodo *q, TNodo *t);
TNodo* eliminaRepetidos(TNodo* p);
float evaluarPolinomio(TNodo* p, int grado,float x);





int main(){
    cout << "Listas simples y circulares simples" << endl;
    system("Pause");
    int op;
    do{
        system("cls");
        cout<<endl<<"      Menu";
        cout<<endl<<"1. Listas Simples";
        cout<<endl<<"2. Listas Circulares";
        cout<<endl<<"3. Ejercicio";
        cout<<endl<<"4. Salir.";
        cout<<endl<<"Selecciona tu opcion: ";
        cin>>op;
        switch(op){
            case 1:
                listasSimples();
                break;
            case 2:
                listasCirculares();
            case 3:
                ejercicios();
            case 4:
                cout<<endl<<"Adios........";
                break;
            default: cout<<endl<<"Opcion no valida"; 
        }
    }while(op!=4);
}

void listasSimples(){
    TNodo *p=NULL;
    int op, dato, ref;
    do{
        cout<<endl;
        system("pause");
        system("cls");
		cout<<"1...Inserta al inicio"<<endl;
		cout<<"2...Inserta al final"<<endl;
		cout<<"3...Inserta antes de una referencia"<<endl;
		cout<<"4...Inserta despues de una referencia"<<endl;
		cout<<"5...Recorre la lista"<<endl;
		cout<<"6...Elimina primero"<<endl;
		cout<<"7...Elimina final"<<endl;
		cout<<"8...Elimina nodo con informacion x"<<endl;
		cout<<"9...Elimina nodo antes de una referencia"<<endl;
		cout<<"10...Elimina nodo despues de una referencia"<<endl;
		cout<<"11...Buscar una referencia"<<endl;
		cout<<"12...Salir"<<endl;
		cout<<"Selecciona tu opcion: ";
		cin>>op;
        switch(op){
            case 1:
                cout<<endl<<"Dato a insertar: ";
                cin>>dato;
                p=insertaInicio(p,dato);
                cout<<endl<<"Dato insertado"<<endl;
                recorre(p);
                break;
            case 2:
                cout<<endl<<"Dato a insertar: ";
                cin>>dato;
                p=insertaFinal(p,dato);
                cout<<endl<<"Dato insertado"<<endl;
                recorre(p);
                break;
            case 3:
                cout<<endl<<"Dato a insertar: ";
                cin>>dato;
                cout<<"Antes de cual referencia: ";
                cin>>ref;
                p=insertaAntes(p,dato,ref);
                recorre(p);
                break;
            case 4:
                cout<<endl<<"Dato a insertar: ";
                cin>>dato;
                cout<<"Despues de cual referencia: ";
                cin>>ref;
                p=insertaDespues(p,dato,ref);
                recorre(p);
                break;
            case 5:
                cout<<endl<<"Datos en lista"<<endl;
                recorre(p);
                cout<<endl;
                break;
            case 6:
                p=eliminaInicio(p);
                recorre(p);
                break;
            case 7:
                p=eliminaFinal(p);
                recorre(p);
                break;
            case 8:
                cout<<endl<<"Cual referencia: ";
                cin>>ref;
                p=eliminaRef(p,ref);
                recorre(p);
                break;
            case 9:
                cout<<endl<<"Antes de cual referencia: ";
                cin>>ref;
                p=eliminaAntes(p,ref);
                recorre(p);
                break;
            case 10:
                cout<<endl<<"Despues de cual referencia: ";
                cin>>ref;
                p=eliminaDespues(p,ref);
                recorre(p);
                break;
            case 11:
                cout<<endl<<"Referencia a buscar: ";
                cin>>ref;
                p=buscaRef(p,ref);
                break;
            case 12: 
                main();
                break;
            default:
                cout << "Opcion No valida" << endl;
                break;

        }
    }while(op!=12);
}


void listasCirculares(){
    int op,dato,ref;
        TNodo *p=NULL;
        do{
            system("cls");
            cout<<"1...Inserta al inicio"<<endl;
            cout<<"2...Inserta al final"<<endl;
            cout<<"3...Inserta antes de una referencia"<<endl;
            cout<<"4...Inserta despues de una referencia"<<endl;
            cout<<"5...Recorre la lista"<<endl;
            cout<<"6...Elimina primero"<<endl;
            cout<<"7...Elimina final"<<endl;
            cout<<"8...Elimina nodo con informacion x"<<endl;
            cout<<"9...Elimina nodo antes de una referencia"<<endl;
            cout<<"10...Elimina nodo despues de una referencia"<<endl;
            cout<<"11...Salir"<<endl;
            cout<<"Selecciona tu opcion: ";
            cin>>op;
            switch(op){
                case 1:
                    cout<<"Dato a insertar: ";
                    cin>>dato;
                    p=insertaInicioCircular(p,dato);
                    cout<<endl<<"Dato insertado"<<endl;
                    system("pause");
                    break;
                case 2:
                    cout<<"Dato a insertar: ";
                    cin>>dato;
                    p=insertaFinalCircular(p,dato);
                    cout<<endl<<"Dato insertado"<<endl;
                    system("pause");
                    break;
                case 3:
                    cout<<"Dato a insertar: ";
                    cin>>dato;
                    cout<<"Antes de cual referencia: ";
                    cin>>ref;
                    p=insertaAntesCircular(p,dato,ref);
                    system("pause");
                    break;
                case 4:
                    cout<<"Dato a insertar: ";
                    cin>>dato;
                    cout<<"Despues de cual referencia: ";
                    cin>>ref;
                    p=insertaDespuesCircular(p,dato,ref);
                    system("pause");
                    break;
                case 5:
                    cout<<endl<<"Datos de la lista"<<endl;
                    recorreCircular(p);
                    cout<<endl;
                    system("pause");
                    break;
                case 6:
                    p=eliminaInicioCircular(p);
                    system("pause");
                    break;
                case 7:
                    p=eliminaFinalCircular(p);
                    system("pause");
                    break;
                case 8:
                    cout<<"cual referencia: ";
                    cin>>ref;
                    p=eliminaReferenciaCircular(p,ref);
                    system("pause");
                    break;
                case 9:
                    cout<<"Antes de cual referencia: ";
                    cin>>ref;
                    p=eliminaAntesCircular(p,ref);
                    recorreCircular(p);
                    system("pause");
                    break;
                case 10:
                    cout << "Despues de cual referencia: ";
                    cin >> ref;
                    p = eliminaDespuesCircular(p,ref);
                    recorreCircular(p);
                    system("pause");
                    break;
                 case 11: 
                main();
                break;
                default:
                     cout << "Opcion No valida" << endl;
                    break;	
            }
            
        }while(op!=11);
}

void listasCirculares2(bool circ){
    int op,dato,ref;
        TNodo *p=NULL;
        p = generaListaCircularAleatoria(p);
        recorreCircular(p);
            if(circ == true){
                cout<<endl<<"cual referencia: ";
                    cin>>ref;
                    p=eliminaReferenciaCircular(p,ref);
                    recorreCircular(p);
                    cout << endl << "Referencia eliminada" << endl;
                   
                    
                
            }
            else{
                cout<<endl<<"Dato a insertar: ";
                    cin>>dato;
                    p=insertaFinalCircular(p,dato);
                    recorreCircular(p);
                    cout<<endl<<"Dato insertado"<<endl;
                    
                   
            }
            
}



void ejercicios()
{
    int op,dato,ref,opcion,cont=1,grado,i;
    TNodo *p=NULL, *q=NULL, *t=NULL, *r=NULL,*lista3=NULL;
    TNodo *Pos=NULL, *Neg=NULL;
    bool circular;
    float x, resultado;
    p = generaListaAleatoria(p);
    r = generaListaAleatoria(r);

    cout << "Lista para trabajar con los ejercicios generada: " << endl;

    recorre(p);
    cout << endl;
    
    do{
         cout<<endl;
        system("pause");
        system("cls");
            cout<<"1...Imprimir de manera recursiva una lista "<<endl;
            cout<<"2...Insertar un elemento antes de un nodo de referencia de una lista ordenada"<<endl;
            cout<<"3...Insertar un elemento que no altere el orden de la lista"<<endl;
            cout<<"4...Eliminar nodo de una lista ordenada"<<endl;
            cout<<"5...Insertar un elemento despues de una referencia de una lista ordenada"<<endl;
            cout<<"6...Formar una lista que sea la mezcla de dos listas"<<endl;
            cout<<"7...Dividir lista en positivos y negativos"<<endl;
            cout<<"8...Meter y sacar pila"<<endl;
            cout<<"9...Buscar referencia de manera recursiva"<<endl;
            cout<<"10...Elimina elemento X de una lista circular"<<endl;
            cout<<"11...Insertar elementos en una lista circular"<<endl;
            cout<<"12...Mezclar dos listas ascendentes y la lista resultante hacerla descendente" << endl;
            cout<<"13...Implementacion de una cola y eliminar repetidos" << endl;
            cout << "14. Evaluar un polinomio, representado por una lista lineal" << endl;
            cout<<"Selecciona tu opcion: ";
            cin>>op;
            switch(op){
                case 1:
                    imprimirListaRecursiva(p);
                    break;
                case 2:
                    p = ordenarLista(p);
                    recorre(p);
                    cout<<endl<<"Dato a insertar: ";
                    cin>>dato;
                    cout<<"Antes de cual referencia: ";
                    cin>>ref;
                    p=insertaAntes(p,dato,ref);
                    recorre(p);
                    break;

                case 3:
                    p = ordenarLista(p);
                    recorre(p);
                    cout<<endl<<"Que dato deseas insertar en la lista ordenada? ";
                    cin>>dato;
                    p=insertaInicio(p,dato);
                    p = ordenarLista(p);
                    recorre(p);
                    cout<<endl<<"Dato insertado"<<endl;
                    break;
                case 4:
                    p = ordenarLista(p);
                    recorre(p);
                    cout<<endl<<"Cual referencia deseas eliminar: ";
                    cin>>ref;
                    p=eliminaRef(p,ref);
                    recorre(p);
                    cout << endl << "Dato eliminado" << endl;
                break;

                case 5:     
                    p = ordenarLista(p);
                    recorre(p);
                    cout<<endl<<"Dato a insertar: ";
                    cin>>dato;
                    cout<<"Despues de cual referencia: ";
                    cin>>ref;
                    p=insertaDespues(p,dato,ref);
                    recorre(p);
                  
                    break;
                case 6:
                    q = generaListaAleatoria(q);
                    cout << "Lista #1: " << endl;
                    recorre(r);
                    cout << endl;
                    cout << "Lista #2: " << endl;
                    recorre(q);
                    cout << endl;
                    system("pause");
                    lista3 = mezclarListas(r,q);
                    cout << "Lista #3: " << endl;
                    recorre(lista3);
                    break;
                case 7: 
                    cout << "Lista generada: " << endl;
                    recorre(p);
                    cout << endl;
                    dividirLista(p, Pos, Neg);
                    cout << "Lista de numeros positivos:" << endl;
                    recorre(Pos);
                    cout << endl;
                    cout << "Lista de numeros negativos:" << endl;
                    recorre(Neg);
               
                    break;
                case 8: 
                    cout << "Imprimiendo pila..." << endl;
                    recorre(p);
                    cout << endl << "Que deseas hacer" << endl;
                    cout << "1. Meter en la pila" << endl;
                    cout << "2. Sacar en la pila" << endl;
                    cout << "escoge una opcion" << endl;
                    cin >> opcion;
                    if(opcion == 1){
                        cout << endl << "Que dato deseas insertar?: " << endl;
                        cin >> dato;
                        insertaFinal(p,dato);
                        recorre(p);
                        cout << "Dato insertado en la pila" << endl;
                    }else if(opcion == 2){
                        eliminaFinal(p);
                        recorre(p);
                        cout << endl << "Dato eliminado de la pila" << endl;
                    }
                    break;
                case 9:
                    cout << "Lista generada: " << endl;
                    recorre(p);
                    cout << endl;
                    cout<<endl<<"Que dato desea buscar dentro de la lista: ";
                    cin>>ref;
                    if(buscar(p,ref))
                    {
                        cout<<endl<<"El dato "<<ref<<" si esta en la lista"<<endl;
                    }
                    else
                    {
                        cout<<endl<<"El dato "<<ref<<" no esta en la lista"<<endl; 
                    }


                    break;
                case 10: 
                    circular = true;
                    listasCirculares2(circular);


                    break;
                case 11:

                    circular = false;
                    listasCirculares2(circular);
                    break;
                
                case 12:
                    q = generaListaAleatoria(q);
                    recorre(q);
                    cout << endl;
                    recorre(p);
                    cout << endl;
                    system("pause");
                    lista3 = mezclarListas(p,q);
                    recorre(lista3);
                    lista3 = ordenaRecursivo(lista3,q,t);
                    recorre(lista3);
                    break;
                case 13:       
                        recorre(p);
                        cout << endl << "Cola generada" << endl;
                        cout << endl;
                        do{

                        
                            cout << "Que deseas hacer" << endl;
                            cout << "1. Meter en la cola" << endl;
                            cout << "2. Sacar de la cola" << endl;
                            cout << "3. Eliminar elementos repetidos de la cola" << endl;
                            cout << "4. Salir" << endl;
                            cout << "escoge una opcion" << endl;
                            cin >> opcion;
                            if(opcion == 1){
                                cout << endl << "Que dato deseas insertar?: " << endl;
                                cin >> dato;
                                p = insertaFinal(p,dato);
                                recorre(p);
                                cout << "Dato insertado en la cola" << endl;
                            }else if(opcion == 2){
                                p = eliminaInicio(p);
                                recorre(p);
                                cout << endl << "Dato eliminado de la pila" << endl;
                            }
                            else if(opcion == 3){
                                p = eliminaRepetidos(p);
                                recorre(p);
                                cout << "elementos repetidos eliminados" << endl;

                            }

                        }while(opcion != 4);
                    
                
                break;

                case 14: 
                    cout << "Ingrese el grado del polinomio: ";
                    cin >> grado;
                    
                    cout << "Ingrese el valor de x para evaluar el polinomio: ";
                    cin >> x;

                    resultado = evaluarPolinomio(p, grado, x);
                    cout << "El resultado de evaluar el polinomio es: " << resultado << endl;
                    break;

                
            

            }

    }while(op!=15);




}



TNodo *crea(){
    return(new TNodo);
}

void quita(TNodo *aux){
    delete aux;
}

//Prototipos Listas Simples
TNodo *insertaFinal(TNodo *p, int dato){
    TNodo *q=NULL, *t=NULL;
    if(p==NULL){
        p=crea();
        p->info=dato;
        p->liga=NULL;
    }else{
        q=crea();
        q->info=dato;
        q->liga=NULL;
        t=p;
        while(t->liga!=NULL){
            t=t->liga;
        }
        t->liga=q;
    }
    return p;
}

TNodo *insertaInicio(TNodo *p, int dato){
    TNodo *q=NULL;
    if(p==NULL){ //crea nodo de cabecera
        p=crea();
        p->info=dato;
        p->liga=NULL;
    }else{
        q=crea();
        q->info=dato;
        q->liga=p;
        p=q;
    }
    return p;
}

void recorre(TNodo *p){
    TNodo *t=p;
    if(p == NULL){
        cout<<"No hay elementos a mostrar"<<endl;
    }else{
        while(t != NULL){
            cout<<"["<<t->info<<"]";
            t=t->liga;
        }
    }
}

TNodo *insertaAntes(TNodo *p, int dato, int ref){
    TNodo *q = NULL, *r = NULL, *t = NULL;
    bool band = true;
    q = p;
    if (p == NULL)
    {
        cout << "Lista vacia" << endl;
    }
    else
    {
        while (q->info != ref && band)
        {
            if (q->liga == NULL)
            {
                band = false;
                cout << "No se encontro el dato de referencia" << endl;
            }
            else
            {
                t = q;
                q = q->liga;
            }
        }
        if (band)
        {
            r = crea();
            r->info = dato;
            if (q == p)
            {
                r->liga = q;
                p = r;
            }
            t->liga = r;
            r->liga = q;
            cout << "Dato insertado" << endl;
        }
        else
        {
            cout << "No se encontro el dato de referencia" << endl;
        }
    }
    return (p);
} 

TNodo *insertaDespues(TNodo *p, int dato, int ref){
    TNodo *q=p, *t=NULL;
    float band=false;
    if(p==NULL){
        cout<<endl<<"Lista vacia";
    }
    else{
        while(q!=NULL && !band){
            if(q->info==ref){
                band=true;
            }else{
                q=q->liga;
            }
        }
        if(band){
            t=crea();
            t->info=dato;
            t->liga=q->liga;
            q->liga=t;
        }else{
            cout<<endl<<"Referencia no encontrada";
        }
    }
    return (p);
}

TNodo *eliminaInicio(TNodo *p){
    TNodo *q=p;
    if(p==NULL){
        cout<<endl<<"Lista Vacia. ";
    }else{
        q=q->liga;
        quita(p);
        cout<<endl<<"Nodo eliminado"<<endl;
        p=q;
    }
    return (p);
}

TNodo *eliminaRef(TNodo *p, int ref){
    TNodo *q=p, *t=p;
    bool band=false;
    
    if(p==NULL){
        cout<<endl<<"Lista Vacia. ";
    }else{
        while(q!=NULL && !band){
            if(q->info==ref){
                band=true;
            }else{
                t=q;
                q=q->liga;
            }
        }
        if(band){
            if(q==p){
                if(p->liga==NULL){
                    p=NULL;
                }else{
                    p=p->liga;
                }
            }else{
                t->liga=q->liga;
            }
            quita(q);
            cout<<endl<<"Nodo eliminado"<<endl;
        }else{
            cout<<endl<<"No se encontro la referencia"<<endl;
        }
    }
    return (p);
}

TNodo *eliminaFinal(TNodo *p){
    TNodo *q=p, *t=NULL;
    if(p==NULL){
        cout<<endl<<"Lista vacia. ";
    }else{
        if(p->liga==NULL){
            quita(p);
            p=NULL;
        }else{
            while(q->liga!=NULL){
                t=q;
                q=q->liga;
            }
            quita(q);
            cout<<endl<<"Nodo eliminado"<<endl;
            t->liga=NULL;
        }
    }
    return (p);
}

TNodo *eliminaAntes(TNodo *p, int ref){
    TNodo *q=p, *t, *r;
    bool band=true;
    if(p==NULL){
        cout<<endl<<"La lista esta vacia no hay nodo a eliminar"<<endl;
    }else{
        if(p->info==ref){
            cout<<endl<<"No hay nodo antes de la referencia"<<endl;
        }else{
            q=t=p;
            while(q->info!=ref && band){
                if(q->liga==NULL){
                    band=false;
                }else{
                    r=t;
                    t=q;
                    q=q->liga;
                }//fin if
            }//fin while
            if(band){
                if(p->liga==q){
                    p=p->liga;
                }else{
                    r->liga=q;
                }
                quita(t);
                cout<<endl<<"Nodo eliminado"<<endl;
            }else{
                cout<<endl<<"Referencia no encontrada, nodo no eliminado"<<endl;
            }
        }
    }
    return (p);
}

TNodo *eliminaDespues(TNodo *p, int ref){
    TNodo *q=p, *t=p;
    bool band=true;
    if(p==NULL){
        cout<<endl<<"La lista esta vacia no hay nodo a eliminar"<<endl;
    }else{
        while(q->info!=ref && band){
            if(q->liga==NULL){
                band=false;
            }else{
                q=q->liga;
                t=q;
            }
        }
        if(band){
            if(q->liga==NULL){
                cout<<endl<<"No hay nodo despues de la referencia"<<endl;
            }else{
                q=q->liga;
                t->liga=q->liga;
                quita(q);
                cout<<endl<<"Nodo eliminado"<<endl;
            }
        }else{
            cout<<endl<<"Referencia no encontrada"<<endl;
        }
    }
    return (p);
}

TNodo *buscaRef(TNodo *p, int ref){
    TNodo *q=p;
    bool band=false;
    int cont=1;
    if(p==NULL){
        cout<<endl<<"Lista vacia"<<endl;
    }else{
        while(q!=NULL && !band){
            if(q->info==ref){
                band=true;
            }else{
                q=q->liga;
                cont++;
            }
        }
        if(band){
            cout<<endl<<"Referencia encontrada en nodo #"<<cont<<endl;
        }else{
            cout<<endl<<"Referencia no encontrada"<<endl;
        }
    }
    return (p);
}

//funciones para ListasCirculares






TNodo* insertaInicioCircular(TNodo *p, int dato){
	TNodo *q=NULL,*t=p;
	if(p==NULL){//crea nodo de cabecera
		p=crea();
		p->info=dato;
		p->liga=p;
	}else{
		q=crea();
		q->info=dato;
		q->liga=p;
		while(t->liga!=p)
		     t=t->liga;
		t->liga=q;
		p=q;
	}
	return (p);
}
TNodo* insertaFinalCircular(TNodo *p, int dato){
	TNodo *t=NULL,*q=NULL;
	if(p==NULL){//crea nodo de cabecera
		p=crea();
		p->info=dato;
		p->liga=NULL;
	}else{
		q=crea();
		q->info=dato;
		q->liga=p;
		t=p;
		while(t->liga!=p)
			t=t->liga;
		t->liga=q;
	}
	return (p);
}
void recorreCircular(TNodo *p){
	TNodo *t=NULL;
	if(p==NULL){
		cout<<endl<<"Lista vacia, nada que mostrar"<<endl;
	}else{
		t=p;
	    do{
	    	cout<<"["<<t->info<<"]";
	    	t=t->liga;
		}while(t!=p);
	}
}


TNodo * insertaAntesCircular(TNodo *p, int dato,int ref){
	TNodo *q=NULL,*t=NULL,*r=NULL;
	bool band=true;
	q=p;
	if(p==NULL){
		cout<<endl<<"Lista vacia, no hay referencia, nodo no isertado"<<endl;
	}else{
		while(q->info!=ref && band==true){
			if(q->liga!=NULL){
				t=q;
				q=q->liga;
			}else{
				band=false;
			}//fin if
		}//fin while
		if(band==true){
			r=crea();
			r->info=dato;
			if(q==p){
				r->liga=q;
				p=r;
			}else{
				t->liga=r;
				r->liga=q;
			}
			cout<<endl<<"Dato insertado"<<endl;
		}else{
			cout<<endl<<"Referencia no encontrada, nodo no isertado"<<endl;
		}
	}
	return p;
}

TNodo* insertaDespuesCircular(TNodo *p, int dato, int ref){
    TNodo *q = p, *t = NULL;
    bool band = true;
    if (p == NULL){
        cout << endl << "Lista vacía, nodo no insertado" << endl;
    }else{
        do{
            if (q->info == ref){
                band = false;
                t = crea();
                t->info = dato;
                t->liga = q->liga;
                q->liga = t;
                cout << endl << "Dato insertado" << endl;
            }else{
                q = q->liga;
            }
        } while (q != p && band);
        if (band){
            cout << endl << "Referencia no encontrada, nodo no insertado" << endl;
        }
    }
    return p;
}
//Elimina
TNodo *eliminaInicioCircular(TNodo *p){
	TNodo *q=p,*t=p;
	if(p==NULL){
		cout<<endl<<"Lista vacia no hay nodo a eliminar"<<endl;
	}else{
		if(q->liga!=p){
			
            while(t->liga!=p){
                t=t->liga;
            }
            p=p->liga;
            t->liga = p;
		}else{
			p=NULL;
		}
		quita(q);
		cout<<endl<<"Nodo eliminado"<<endl;
	}
	return (p);
}
TNodo *eliminaFinalCircular(TNodo *p){
	TNodo *q=p,*t; //q va a ser el nodo con el q busque el final de la lista
	if(p==NULL){ //Si la lista esta vacia, no hay nada q hacer
		cout<<endl<<"Lista vacia no hay nodo a eliminar"<<endl;
	}else{
		if(q->liga!=p){
			while(q->liga!=p){
				t=q;
				q=q->liga;
			}
			t->liga=p;
		}else{
			p=NULL;
		}
		quita(q);
		cout<<endl<<"Nodo eliminado"<<endl;
	}
	return (p);
}
TNodo *eliminaAntesCircular(TNodo *p,int ref){
	TNodo *q=p,*t,*r;
	bool band=true;
	if(p==NULL){
		cout<<endl<<"Lista vacia no hay nodo a eliminar"<<endl;
	}else{
		if(p->info==ref){
			cout<<endl<<"no hay nodo antes de la referencia"<<endl;
		}else{
			q=t=p;
			while(q->info!=ref && band==true){
				if(q->liga==p){
					band=false;
				}else{
					r=t;
					t=q;
					q=q->liga;
				}//fin if
			}//fin while
			if(band==true){
				if(p->liga==q){
					
                    while(r->liga!=p){
                        r = r->liga;
                    }
                    p=p->liga;
                    r->liga = p;
				}else{
					r->liga=q;
				}//finif
				quita(t);
				cout<<endl<<"Nodo eliminado"<<endl;
			}else{
				cout<<endl<<"Referencia no encontrada, nodo no eliminado"<<endl;
			}//fin if
		}//fin if
	}//fin if(p==NULL)
	return (p);
}
TNodo *eliminaReferenciaCircular(TNodo *p,int ref){
	TNodo *q=p,*t;
	bool band=true;
	if(p==NULL){
		cout<<endl<<"Lista vacia no hay nodo a eliminar"<<endl;
	}else{
		while(q->info!=ref && band==true){
			if(q->liga==NULL){
				band=false;
			}else{
				t=q;
				q=q->liga;
			}//fin if(->liga==NULL)
		}//fin while
		if(band==false){
			cout<<endl<<"Referencia no encontrada, nodo no eliminado"<<endl;
		}else{
			if(p==q){
				p=p->liga;
			}else{
				t->liga=q->liga;
			}
			quita(q);
		}
	}//fin if(p==NULL)
	return(p);
}



TNodo *eliminaDespuesCircular(TNodo *p, int ref){
    TNodo *q = p, *t = NULL;
    bool band = true;
    if (p == NULL){
        cout << endl << "Lista vacía, nodo no eliminado" << endl;
    }else{
        do{
            if (q->info == ref){
                band = false;
                if (q->liga != q){
                    t = q->liga;
                    q->liga = t->liga;
                    quita(t);
                    cout << endl << "Nodo eliminado" << endl;
                }else{
                    cout << endl << "No hay nodo después de la referencia para eliminar" << endl;
                }
            }else{
                q = q->liga;
            }
        } while (q != p && band);
        if (band){
            cout << endl << "Referencia no encontrada, nodo no eliminado" << endl;
        }
    }
    return p;
}


//Ejercicios


TNodo* generaListaAleatoria(TNodo *p) {
    srand(time(0)); 
    p = NULL; 
    
    for (int i = 0; i < 10; i++) {
        int numAleatorio = rand() % 31 - 10; 
        p = insertaFinal(p, numAleatorio);
    }
    return p;
}
TNodo* generaListaCircularAleatoria(TNodo *p) {
    srand(time(0)); 
    TNodo *inicio = NULL; 
    TNodo *ultimo = NULL; 

    for (int i = 0; i < 10; i++) {
        int numAleatorio = rand() % 31 - 10; 
        TNodo *q = crea(); 
        q->info = numAleatorio;

        if (inicio == NULL) {
            inicio = q;
            ultimo = q;
            q->liga = inicio; 
        } else {
           
            q->liga = inicio; 
            ultimo->liga = q; 
            ultimo = q; 
        }
    }
    return inicio; 
}





void imprimirListaRecursiva(TNodo *p) {
    if (p == NULL) {
        cout << "La lista está vacía." << endl;
        return;
    }

    cout << "[" << p->info << "]";

    if (p->liga != NULL) {
        cout << " ";
        imprimirListaRecursiva(p->liga);
    } else {
        cout << endl;
    }
}

TNodo* ordenarLista(TNodo *p) {
    TNodo *actual, *minimo;
    int temp;

    if (p == NULL) {
        cout << "La lista esta vacia." << endl;
        return p;
    }

    for (actual = p; actual->liga != NULL; actual = actual->liga) {
        minimo = actual;
        for (TNodo *j = actual->liga; j != NULL; j = j->liga) {
            if (j->info < minimo->info) {
                minimo = j;
            }
        }
        if (minimo != actual) {
            temp = actual->info;
            actual->info = minimo->info;
            minimo->info = temp;
        }
    }

    cout << "Lista ordenada de menor a mayor:" << endl;
    return p;
}

TNodo* mezclarListas(TNodo* lista1, TNodo* lista2) {
    if (lista1 == NULL) {
        return lista2;
    }

    if (lista2 == NULL) {
        return lista1;
    }

    TNodo* temp = lista1;

    while (temp->liga != NULL) {
        temp = temp->liga;
    }

    temp->liga = lista2;

    return lista1;
}

void dividirLista(TNodo* lista, TNodo*& listaPositivos, TNodo*& listaNegativos) {
    TNodo* actual = lista;
    listaPositivos = NULL;
    listaNegativos = NULL;

    while (actual != NULL) {
        if (actual->info >= 0) {
            listaPositivos = insertaInicio(listaPositivos, actual->info);
        } else {
            listaNegativos = insertaInicio(listaNegativos, actual->info);
        }
        actual = actual->liga;
    }
}

TNodo *buscaRefRecursiva(TNodo *p, int ref, int &cont) {
    if (p == NULL) {
        cout << endl << "Lista vacia" << endl;
        return NULL;
    }

    if (p->info == ref) {
        cout << endl << "Referencia encontrada en nodo #" << cont << endl;
        return p;
    }

    cont++;
    return buscaRefRecursiva(p->liga, ref, cont);
}

bool buscar(TNodo *p, int ref)
{
    if(p==NULL)
    {
        return false;
    }
    if(p->info==ref)
    {
        return true;
    }
    return buscar(p->liga, ref);
}


TNodo *ordenaRecursivo(TNodo *p, TNodo *q, TNodo *t){
    int aux;
    if(q->liga!=p){
        if(t!=p){
            if(q->info < t->info){
                aux=q->info;
                q->info=t->info;
                t->info=aux;
            }
            return ordenaRecursivo(p,q,t->liga);
        }
        return ordenaRecursivo(p,q->liga,q->liga);
    }
    return (p);
}

TNodo* eliminaRepetidos(TNodo* p) {
    if (p == NULL) {
        cout << "La lista está vacía." << endl;
        return NULL;
    }

    TNodo* actual = p;
    TNodo* comparador;
    TNodo* temporal;

    while (actual != NULL) {
        comparador = actual;

        while (comparador->liga != NULL) {
            if (comparador->liga->info == actual->info) {
                temporal = comparador->liga;
                comparador->liga = comparador->liga->liga;
                delete temporal;
            } else {
                comparador = comparador->liga;
            }
        }

        actual = actual->liga;
    }

    return p;
}
float evaluarPolinomio(TNodo* p, int grado,float x) 
{
	float termino_actual,resultado_restante,resultado;
    if (p == NULL) 
	{
        return 0.0;
    } else 
	{
         termino_actual = p->info * pow(x, grado);
         resultado_restante = evaluarPolinomio(p->liga, grado - 1, x);
         resultado = termino_actual + resultado_restante;

        return resultado;
    }
}