 
struct Node                             //Структура, являющаяся звеном списка
 {
     long int x;                             //Значение x будет передаваться в список
     Node *Next, *Prev;                 //Указатели на адреса следующего и предыдущего элементов списка
 };
 
 class List                              //Создаем тип данных Список
 {
     Node *Head, *Tail;                 //Указатели на адреса начала списка и его конца
 public:
     List():Head(NULL),Tail(NULL){};    //Инициализируем адреса как пустые
     ~List();                           //Прототип деструктора
     void Show();                       //Прототип функции отображения списка на экране
     void Add(long int x);			  		 //Прототип функции добавления элементов в список
	 void Delete( long int x);			//Это твоя функция удаления
	 void FindErr(long int x);
 };
 
List::~List()                           //Деструктор
 {
     while (Head)                       //Пока по адресу на начало списка что-то есть
     {
         Tail = Head->Next;             //Резервная копия адреса следующего звена списка
         delete Head;                   //Очистка памяти от первого звена
         Head = Tail;                   //Смена адреса начала на адрес следующего элемента
     }
 }
 
 void List::Add(int x)
 {
   Node *temp = new Node;               //Выделение памяти под новый элемент структуры
   temp->Next = NULL;                   //Указываем, что изначально по следующему адресу пусто
   temp->x = x;                         //Записываем значение в структуру
 
   if (Head != NULL)                    //Если список не пуст
   {
       temp->Prev = Tail;               //Указываем адрес на предыдущий элемент в соотв. поле
       Tail->Next = temp;               //Указываем адрес следующего за хвостом элемента
       Tail = temp;                     //Меняем адрес хвоста
   }
   else //Если список пустой
   {
       temp->Prev = NULL;               //Предыдущий элемент указывает в пустоту
       Head = Tail = temp;              //Голова=Хвост=тот элемент, что сейчас добавили
   }
 }
 

 ФУНКЦИЯ УДАЛЕНИЯ КОНКРЕТНОГО ЭЛЕМЕНТА ДВУСВЯЗНОГО СПИСКА*/
    void List::Delete(long int x){
                            //Если удаляем первый элемент, то могут быть такие варианты
                            //В списке есть только первый, в списке есть несколько элементов
                            //Поэтому разбиваем логику выполнения
            if ((x == 1) and (Head->Next)){                     //Если удаляем первый, но есть и другие, то
                List *temp = Head;	                        //Указываем, что нам нужно начало списка
                Head = Head->Next;	                            //Сдвигаем начало на следующий за началом элемент
                Head->Prev = NULL;	                            //Делаем так, чтоб предыдущий началу элемент был пустым
                delete temp;		                            //Удаляем удаляемое начало
                count_--;		                                //Обязательно уменьшаем счетчик
                return ;		                                //И выходим из функции
            } else if ((x == 1) and (Head == Tail)){            //Если удаляем первый, но в списке только 1 элемент

                Head->Next = NULL;	                            //обнуляем все что нужно
                Head = NULL;
                delete Head;		                            //Удаляем указатель на начало
                count_ = 0;		                                //Обязательно обозначаем, что в списке ноль элементов
                return;			                                //и выходим из функции
            }

        //Также может быть, что удаляемый элемент является последним элементом списка
        if (x==count_){
            List *temp = Tail;	                            //Указываем, что нам нужен хвост
            Tail = Tail->Prev;	                                //Отодвигаем хвост немного назад
            Tail->Next = NULL;	                                //Обозначаем, что впереди за хвостом пусто
            delete temp;	                                    //Очищаем память от бывшего хвоста
            count_--;		                                    //Обязательно уменьшаем счетчик элементов
                return;		                                    //И выходим из функции
            }


 
 void List::Show()
 {
//ВЫВОДИМ СПИСОК С КОНЦА
     Node *temp=Tail;                   //Временный указатель на адрес последнего элемента
 
     while (temp != NULL)               //Пока не встретится пустое значение
     {
         cout << temp->x << " ";        //Выводить значение на экран
         temp = temp->Prev;             //Указываем, что нужен адрес предыдущего элемента
     }
     cout << "\n";
 
 //ВЫВОДИМ СПИСОК С НАЧАЛА
     temp = Head;                       //Временно указываем на адрес первого элемента
      while (temp != NULL)              //Пока не встретим пустое значение
     {
         cout << temp->x << " ";        //Выводим каждое считанное значение на экран
         temp = temp->Next;             //Смена адреса на адрес следующего элемента
     }
     cout << "\n";
 }
 
int main ()
{
 system("CLS");
 List lst; //Объявляем переменную, тип которой есть список
 lst.Add(100); //Добавляем в список элементы
 lst.Add(200);
 lst.Add(900);
 lst.Add(888);
 
 lst.Show(); //Отображаем список на экране
  system("PAUSE");
    return 0;
}