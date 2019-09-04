#include <iostream>
using namespace std;


struct Nodo{
	int dato;
	Nodo *sig;
};

class Cola{
	
	private: 
		Nodo *inicio;
		Nodo *fin;
	
	public: 
		Nodo* crearNodo(int valor){
			Nodo *n = new Nodo;
			n-> dato = valor;
			n->sig = nullptr;
			return n;
		}
		
		void mostrarCola(){
			Nodo *temp = inicio;
			if(!inicio){
				cout<<"cola vacia";
				
			}else{
				while(temp){
					cout<<temp->dato<<" - ";
					temp = temp -> sig;
				}
			}
		}

void push(int valor){
			Nodo *n = crearNodo(valor);
			
			if(!inicio){
				inicio = n;
				fin = n;
			}else{
				fin -> sig = n;
				fin = n;
			}
		}


    void pop(){
			Nodo *temp = inicio;
			
			inicio = inicio -> sig;
			free(temp);
		}


  int SizeCola(){
    int size=0;
    Nodo *temp = inicio;
    if(!inicio){
      cout<<"Cola vacia"<<endl;
      
    }

    else{
      while(temp){
      size++;
      temp = temp->sig;
      }


    }

    return size;
  }




  int ColaProm(){
      int contador=0, acum= 0, promedio=0;
    	Nodo *temp = inicio;
			if(!inicio){
				cout<<"cola vacia";
				
			}else{
				while(temp){
          acum+= temp->dato;
          temp = temp -> sig;
          contador++;
				}
			}

      promedio= acum/contador;
      return promedio;
  }


int accederDato(int posi){
  int contador=0;
  Nodo *temp = inicio;
			if(!inicio){
				cout<<"cola vacia";
				
			}else{
				while(temp && contador!=posi){
          temp = temp->sig;
          contador++;
				}

       
			} 
  return temp->dato;
}


  Cola(){
			this -> inicio = nullptr;
			this -> fin = nullptr;
		}


};



int main() {


  Cola cola;
	Cola cola2;
	
  cola.push(5);
	cola.push(10);
	cola.push(15);

  cout<<"Cola 1: "<<endl;
  cola.mostrarCola();
  cout<<endl<<endl<<"El promedio de los números es: "<<cola.ColaProm()<<endl;
  cout<<endl;
  
  for(int i=0; i<cola.SizeCola();i++){
    if(cola.accederDato(i)%cola.ColaProm()==0){
      cola2.push(cola.accederDato(i));
    }

  }

  cout<<"Cola 2: "<<endl;
  cola2.mostrarCola();
}
