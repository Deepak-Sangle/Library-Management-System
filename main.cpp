#include<bits/stdc++.h>
#include<stack>
#include<vector>
#include<iostream>
#include<utility>
#include<iterator>
#include<algorithm>
#include<numeric>
#include <time.h>
using namespace std;

//Declaring function 
void LoginPage();
void HomePage();
void LoginPage_for_Student();
void LoginPage_for_Librarian();
void LoginPage_for_Profesor();

class Book{
    private:
    
    public:
        int num_of_days,issuedDate;
        string isIssued, Title, Author, ISBN, Publication, issuedBy;
        Book(string Title, string Author, string ISBN, string Publication,string issuedBy, string isIssued, int issuedDate);
};

Book::Book(string Title, string Author, string ISBN, string Publication,string issuedBy, string isIssued, int issuedDate){
    this->Title = Title;
    this->Author = Author;
    this->ISBN = ISBN;
    this->Publication = Publication;
    this->issuedBy = issuedBy;
    this->isIssued = isIssued;
    this->issuedDate = issuedDate;
    
}

class User{
    private:
    
    public:
        string name;
        string id;
        void Check_Availability();
        string password;
        int identifier;
};


class Book_Database{
    private:

    public:
        Book_Database();
        vector<Book> Book_DB;
        void Display();
        void Add();
        void Update();
        void Delete();
};

Book_Database::Book_Database(){

}

class Student: public User{
    private:

    public:
        int fineAmount;
        vector <Book> List_of_Books;
        Student(string name, string id, string password, int fineAmount);
        void Display_my_Books();
        void Issue_Book();
        void Fine_amount();
        void Clear_fine_amount();
};

Student::Student(string name, string id, string password, int fineAmount){
    this->name = name;
    this->id = id;
    this->password = password;
    this->identifier = 1;
    this->fineAmount = fineAmount;
}

class Librarian: public User{
    private:

    public:
        Librarian(string name, string id, string password);
        void check_what_issued();
        void check_whom_issued();      
};

Librarian::Librarian(string name, string id, string password){
    this->name = name;
    this->id = id;
    this->password = password;
    this->identifier = 3;
}

class Profesor: public User{
    private:

    public:
        int fineAmount;
        vector <Book> List_of_Books;        
        Profesor(string name, string id, string password,int fineAmount);
        void Display_my_Books();
        void Issue_Book();
        void Fine_amount();
        void Clear_fine_amount();
};

Profesor::Profesor(string name, string id, string password,int fineAmount){
    this->name = name;
    this->id = id;
    this->password = password;
    this->identifier = 2;
    this->fineAmount = fineAmount;
}

class User_Database{
    private:

    public:
        User_Database();
        vector <Student> Student_DB;
        vector <Profesor> Profesor_DB;
        vector <Librarian> Librarian_DB;
        void Add();
        void Update();
        void Delete();
        void Display();
};

User_Database::User_Database(){

}

void Logout(){
    cout<<"Logging out of the system...\n";
    cout<<"You are being redirected to login page\n";
    LoginPage();
    return ;
}

int ValidateInput(string input){
    int i,n=input.length(), caseinput;
    for(i=0;i<n;i++){
        if(isdigit(input[i])==false) break;  
    }
    if(i!=n){
        cout<<"Invalid Input\n";
        return -100;
    }
    return stoi(input);
}

//Globally Initialized the user and book database for our programme;
User_Database user_db;
Book_Database book_db;

void read_student_db(){
    string fname = "student_db.csv";
    vector<string> row;
	string line, word;
	fstream file (fname, ios::in);
    //Reading Student's Databases
	if(file.is_open()){
		while(getline(file, line)){
			row.clear();
			stringstream str(line);
			while(getline(str, word, ','))
				row.push_back(word);
            int fineAmount = stoi(row[3]);
            Student temp(row[0],row[1],row[2],fineAmount);
            user_db.Student_DB.push_back(temp);
		}
	}
	else{
		cout<<"Could not open the file\n";
        return ;
    }
    file.close();
    return ;
}

void read_professor_db(){
    string fname = "professor_db.csv";
    vector<string> row;
	string line, word;
	fstream file (fname, ios::in);
    //Reading Student's Databases
	if(file.is_open()){
		while(getline(file, line)){
			row.clear();
			stringstream str(line);
			while(getline(str, word, ','))
				row.push_back(word);
            int fineAmount = stoi(row[3]);
            Profesor temp(row[0],row[1],row[2], fineAmount);
            user_db.Profesor_DB.push_back(temp);
		}
	}
	else{
		cout<<"Could not open the file\n";
        return ;
    }
    file.close();
    return ;
}

void read_librarian_db(){
    string fname1 = "librarian_db.csv";
    vector<string> row;
	string line, word;
	fstream file (fname1, ios::in);
    //Reading Student's Databases
	if(file.is_open()){
		while(getline(file, line)){
			row.clear();
			stringstream str(line);
			while(getline(str, word, ','))
				row.push_back(word);
            Librarian temp(row[0],row[1],row[2]);
            user_db.Librarian_DB.push_back(temp);
		}
	}
	else{
		cout<<"Could not open the file\n";
        return ;
    }
    file.close();
    return ;
}

void read_book_db(){
    string fname = "book_db.csv";
    vector<string> row;
	string line, word;
	fstream file (fname, ios::in);
    //Reading Student's Databases
	if(file.is_open()){
		while(getline(file, line)){
			row.clear();
			stringstream str(line);
			while(getline(str, word, ','))
				row.push_back(word);
            int issueDate = stoi(row[6]);
            Book temp(row[0],row[1],row[2],row[3],row[4],row[5],issueDate);
            book_db.Book_DB.push_back(temp);
		}
	}
	else{
		cout<<"Could not open the file\n";
        return ;
    }
    file.close();
    return ;
}

void read_csv_files(){
    read_student_db();
    read_professor_db();
    read_librarian_db();
    read_book_db();
    return ;
}

void Initialize_Database(){
    int n = book_db.Book_DB.size();
    for(int i=0;i<n;i++){
        string name = book_db.Book_DB[i].issuedBy; 
        if(name!=""){
            for(int j=0;j<user_db.Student_DB.size();j++){
                if(user_db.Student_DB[j].name==name) {
                    user_db.Student_DB[j].List_of_Books.push_back(book_db.Book_DB[i]);
                    break;;
                }
            }
            for(int j=0;j<user_db.Profesor_DB.size();j++){
                if(user_db.Profesor_DB[j].name==name) {
                    user_db.Profesor_DB[j].List_of_Books.push_back(book_db.Book_DB[i]);
                    break;;
                }
            }
        }
    }
    return ;
}

void update_book_db(){
    fstream fout;
    int n = book_db.Book_DB.size();
    fout.open("temporary.csv", ios::out);
    for(int i=0;i<n;i++){
        fout << book_db.Book_DB[i].Title<<",";
        fout << book_db.Book_DB[i].Author<<",";
        fout << book_db.Book_DB[i].ISBN<<",";
        fout << book_db.Book_DB[i].Publication<<",";
        fout << book_db.Book_DB[i].issuedBy<<",";
        fout << book_db.Book_DB[i].isIssued<<",";
        if(i!=n-1) fout << book_db.Book_DB[i].issuedDate<<"\n";
        else fout << book_db.Book_DB[i].issuedDate;
    }
    fout.close();
    remove("book_db.csv");
    rename("temporary.csv", "book_db.csv");
    return ;
}

void update_student_db(){
    fstream fout;
    int n = user_db.Student_DB.size();
    fout.open("temporary.csv", ios::out);
    for(int i=0;i<n;i++){
        fout<<user_db.Student_DB[i].name<<",";
        fout<<user_db.Student_DB[i].id<<",";
        fout << user_db.Student_DB[i].password<<",";
        if(i!=n-1) fout << user_db.Student_DB[i].fineAmount<<"\n";
        else fout <<  user_db.Student_DB[i].fineAmount;
    }
    fout.close();
    remove("student_db.csv");
    rename("temporary.csv", "student_db.csv");
    return ;
}

void update_professor_db(){
    fstream fout;
    int n = user_db.Profesor_DB.size();
    fout.open("temporary.csv", ios::out);
    for(int i=0;i<n;i++){
        fout<<user_db.Profesor_DB[i].name<<",";
        fout<<user_db.Profesor_DB[i].id<<",";
        fout<<user_db.Profesor_DB[i].password<<",";
        if(i!=n-1) fout << user_db.Profesor_DB[i].fineAmount<<"\n";
        else fout <<  user_db.Profesor_DB[i].fineAmount;
    }
    fout.close();
    remove("professor_db.csv");
    rename("temporary.csv", "professor_db.csv");
    return ;
}

void Book_Database::Display(){
    int n = book_db.Book_DB.size();
    cout<<"Total number of books are "<<n<<endl;
    cout<<"Sr. \t\tTitle \t\tAuthor \t\tISBN \t\tPublication \n";
    for(int i=0;i<n;i++){
        cout<<i+1<<"\t\t"<<book_db.Book_DB[i].Title<<"\t\t"<<book_db.Book_DB[i].Author<<"\t\t"<<book_db.Book_DB[i].ISBN<<"\t\t"<<book_db.Book_DB[i].Publication<<"\n";
    }
    return ;
}

void Book_Database::Add(){
    string title, author, isbn, publication;
    cout<<"Enter the details of the book to be added\n";
    cout<<"Title: ";   cin>>title; 
    cout<<"Author: ";  cin>>author; 
    cout<<"ISBN: ";  cin>>isbn;
    cout<<"Publication: ";  cin>>publication; 
    Book temp(title, author, isbn, publication, "", "no", -1);
    book_db.Book_DB.push_back(temp);
    update_book_db();
    return ;
}

void Book_Database::Update(){
    string title, author, isbn, publication;
    cout<<"Enter the Title of the book to be updated\n";
    cout<<"Title: ";   cin>>title; 
    int len = book_db.Book_DB.size();
    for(int i=0;i<len;i++){
        if(book_db.Book_DB[i].Title == title){
            cout<<"Enter the details of the book to be updated\n";
            cout<<"new Title: ";   cin>>title; 
            cout<<"new Author: "; cin>>author;
            cout<<"new ISBN: ";  cin>>isbn; 
            cout<<"new Publication: ";  cin>>publication; 
            book_db.Book_DB[i].Title = title; 
            book_db.Book_DB[i].Author = author;
            book_db.Book_DB[i].ISBN = isbn;
            book_db.Book_DB[i].Publication = publication;
            update_book_db();
            return;
        }
    }
    cout<<"There does not exists any book titled "<<title<<endl;
    return ;
}

void Book_Database::Delete(){
    string title;
    cout<<"Enter the Title of the book to be deleted\n";
    cout<<"Title: ";  cin>>title;
    int len = book_db.Book_DB.size();
    for(int i=0;i<len;i++){
        if(book_db.Book_DB[i].Title == title){
            book_db.Book_DB.erase(book_db.Book_DB.begin()+i);
            cout<<"The Book has been deleted";            
            update_book_db();
            return ;
        }
    }
    cout<<"There does not exists any book titled "<<title<<endl;
    return ;
}

void User_Database::Add(){
    int user_num;
    string name, id, password,input;
    cout<<"Press 1 to Add Student\nPress 2 to Add Profesor: ";
    cin>>input;
    user_num = ValidateInput(input);
    while(user_num!=1 && user_num!=2){
        cout<<"Invalid input! Press either 1 or 2: ";
        cin>>user_num;
    }
    cout<<"Enter the details of the user to be added\n";
    cout<<"Name: ";  cin>>name;
    cout<<"ID: ";  cin>>id;
    cout<<"Password: ";  cin>>password;
    if(user_num==1){
        Student temp(name, id, password,0);
        user_db.Student_DB.push_back(temp);
        update_student_db();
    }
    else if(user_num==2){
        Profesor temp(name, id, password,0);
        user_db.Profesor_DB.push_back(temp);
        update_professor_db();
    }
    cout<<"The user has been added succesfully:)\n";
    return ;
}

void User_Database::Update(){
    int user_num;
    string name, id, password,input;
    cout<<"Press 1 to Update Student\nPress 2 to Update Profesor\n";
    cout<<"Waiting for the user to take input: ";
    cin>>input;
    user_num = ValidateInput(input);
    while(user_num!=1 && user_num!=2){
        cout<<"Invalid input! Press either 1 or 2: ";
        cin>>user_num;
    }
    cout<<"Enter the name of the user to be updated\n";
    cout<<"Name: ";   cin>>name; 
    if(user_num==1){
        int len = user_db.Student_DB.size();
        for(int i=0;i<len;i++){
            if(user_db.Student_DB[i].name==name){
                cout<<"\nEnter the details of the Student to be updated\n";
                cout<<"new Name: "; cin>>name; 
                cout<<"new ID: ";  cin>>id;
                cout<<"new Password: ";  cin>>password;
                user_db.Student_DB[i].name=name;
                user_db.Student_DB[i].id=id;
                user_db.Student_DB[i].password=password;
                update_student_db();
                cout<<"The Database has been updated :)\n";
                return ;
            }
        }
        cout<<"There does not exists any user named "<<name<<endl;
    }
    else if(user_num==2){
        int len = user_db.Profesor_DB.size();
        for(int i=0;i<len;i++){
            if(user_db.Profesor_DB[i].name==name){
                cout<<"\nEnter the details of the Profesor to be updated\n";
                cout<<"new Name: ";   cin>>name; 
                cout<<"new ID: ";  cin>>id;
                cout<<"new Password: ";  cin>>password;
                user_db.Profesor_DB[i].name=name;
                user_db.Profesor_DB[i].id=id;
                user_db.Profesor_DB[i].password=password;
                update_professor_db();
                cout<<"The Database has been updated :)\n";
                return ;
            }
        }
        cout<<"There does not exists any user named "<<name<<endl;
    }
    return ;
}

void User_Database::Delete(){
    int user_num;
    string input,name, id, password;
    cout<<"Press 1 to Delete Student\nPress 2 to Delete Profesor\n";
    cout<<"Waiting for the user to take input: ";
    cin>>input;
    user_num = ValidateInput(input);
    while(user_num!=1 && user_num!=2){
        cout<<"Invalid input! Press either 1 or 2: ";
        cin>>user_num;
    }
    cout<<"Enter the name of the user to be deleted\n";
    cout<<"Name: ";   cin>>name;
    if(user_num==1){
        int len = user_db.Student_DB.size();
        for(int i=0;i<len;i++){
            if(user_db.Student_DB[i].name==name){
                user_db.Student_DB.erase(user_db.Student_DB.begin()+i);
                update_student_db();
                cout<<"The Student has been deleted :)\n";
                return ;
            }
        }
        cout<<"There does not exists any user named "<<name<<endl;
    }
    else if(user_num==2){
        int len = user_db.Profesor_DB.size();
        for(int i=0;i<len;i++){
            if(user_db.Profesor_DB[i].name==name){
                user_db.Profesor_DB.erase(user_db.Profesor_DB.begin()+i);
                update_professor_db();
                cout<<"The Profesor has been deleted :)\n";
                return ;
            }
        }
        cout<<"There does not exists any user named "<<name<<endl;
    }
    return ;
}

void User_Database::Display(){
    int len;
    const int numWidth = 18;
    len=user_db.Student_DB.size();
    cout<<"List of All the students are as follows\n";
    // cout<<"Sr. \t\t Name \t\t ID \n";
    cout<<left<<setw(numWidth)<<"Sr. No.";
    cout<<left<<setw(numWidth)<<"Name";
    cout<<left<<setw(numWidth)<<"ID"<<endl;
    for(int i=0;i<len;i++){
        cout<<left<<setw(numWidth)<<to_string(i+1);
        cout<<left<<setw(numWidth)<<user_db.Student_DB[i].name;
        cout<<left<<setw(numWidth)<<user_db.Student_DB[i].id<<endl;
        // cout<<to_string(i+1)<<"\t\t"<<user_db.Student_DB[i].name<<"\t\t"<<user_db.Student_DB[i].id<<"\n";
    }
    len=user_db.Profesor_DB.size();
    cout<<"List of All the professor are as follows\n";
    // cout<<"Sr. \t\t Name \t\t ID \n";
    cout<<left<<setw(numWidth)<<"Sr. No.";
    cout<<left<<setw(numWidth)<<"Name";
    cout<<left<<setw(numWidth)<<"ID"<<endl;
    for(int i=0;i<len;i++){
        cout<<left<<setw(numWidth)<<to_string(i+1);
        cout<<left<<setw(numWidth)<<user_db.Profesor_DB[i].name;
        cout<<left<<setw(numWidth)<<user_db.Profesor_DB[i].id<<endl;
        // cout<<to_string(i+1)<<"\t\t"<<user_db.Profesor_DB[i].name<<"\t\t"<<user_db.Profesor_DB[i].id<<"\n";
    }
    len=user_db.Librarian_DB.size();
    cout<<"List of All the Librarian are as follows\n";
    // cout<<"Sr. \t\t Name \t\t ID \n";
    cout<<left<<setw(numWidth)<<"Sr. No.";
    cout<<left<<setw(numWidth)<<"Name";
    cout<<left<<setw(numWidth)<<"ID"<<endl;
    for(int i=0;i<len;i++){
        cout<<left<<setw(numWidth)<<to_string(i+1);
        cout<<left<<setw(numWidth)<<user_db.Librarian_DB[i].name;
        cout<<left<<setw(numWidth)<<user_db.Librarian_DB[i].id<<endl;
        // cout<<to_string(i+1)<<"\t\t"<<user_db.Librarian_DB[i].name<<"\t\t"<<user_db.Librarian_DB[i].id<<"\n";
    }
    return;
}

void Student::Display_my_Books(){
    const int numWidth = 18;
    int n = this->List_of_Books.size();
    cout<<"Total number of books you own are "<<n<<endl;
    if(n==0) return;
    cout<<left<<setw(numWidth)<<"Sr. No.";
    cout<<left<<setw(numWidth)<<"Title";
    cout<<left<<setw(numWidth)<<"Author";
    cout<<left<<setw(numWidth)<<"ISBN";
    cout<<left<<setw(numWidth)<<"Publication"<<endl;
    // cout<<"Sr. \t\tTitle \t\tAuthor \t\tISBN \t\tPublication \n";
    for(int i=0;i<n;i++){
        // cout<<i+1<<"\t\t"<<this->List_of_Books[i].Title<<"\t\t"<<this->List_of_Books[i].Author<<"\t\t"<<this->List_of_Books[i].ISBN<<"\t\t"<<this->List_of_Books[i].Publication<<"\n";
        cout<<left<<setw(numWidth)<<to_string(i+1);
        cout<<left<<setw(numWidth)<<this->List_of_Books[i].Title;
        cout<<left<<setw(numWidth)<<this->List_of_Books[i].Author;
        cout<<left<<setw(numWidth)<<this->List_of_Books[i].ISBN;
        cout<<left<<setw(numWidth)<<this->List_of_Books[i].Publication<<endl;
    }
    return ;
}

void Profesor::Display_my_Books(){
    const int numWidth = 18;
    int n = this->List_of_Books.size();
    cout<<"Total number of books you own are "<<n<<endl;
    if(n==0) return;
    // cout<<"Sr. \t\tTitle \t\tAuthor \t\tISBN \t\tPublication \n";
    cout<<left<<setw(numWidth)<<"Sr. No.";
    cout<<left<<setw(numWidth)<<"Title";
    cout<<left<<setw(numWidth)<<"Author";
    cout<<left<<setw(numWidth)<<"ISBN";
    cout<<left<<setw(numWidth)<<"Publication"<<endl;
    for(int i=0;i<n;i++){
        // cout<<i+1<<"\t\t"<<this->List_of_Books[i].Title<<"\t\t"<<this->List_of_Books[i].Author<<"\t\t"<<this->List_of_Books[i].ISBN<<"\t\t"<<this->List_of_Books[i].Publication<<"\n";
        cout<<left<<setw(numWidth)<<to_string(i+1);
        cout<<left<<setw(numWidth)<<this->List_of_Books[i].Title;
        cout<<left<<setw(numWidth)<<this->List_of_Books[i].Author;
        cout<<left<<setw(numWidth)<<this->List_of_Books[i].ISBN;
        cout<<left<<setw(numWidth)<<this->List_of_Books[i].Publication<<endl;
    }
    return ;
}

void Student::Issue_Book(){
    int n = this->List_of_Books.size();
    if(n==5){
        cout<<"You have already issued 5 books and cannot issue more books :(\n";
        return ;
    }
    string input;
    cout<<"Enter the Title of the book: ";
    // cin>>input;
    cin.ignore();
    getline(cin,input);
    n=book_db.Book_DB.size();
    for(int i=0;i<n;i++){
        if(book_db.Book_DB[i].Title==input){
            if(book_db.Book_DB[i].isIssued=="yes"){
                cout<<"This book is already issued :(\n";
            }
            else{
                book_db.Book_DB[i].isIssued = "yes";
                this->List_of_Books.push_back(book_db.Book_DB[i]);
                book_db.Book_DB[i].issuedBy = this->name;
                time_t curr_time = time(NULL);
                book_db.Book_DB[i].issuedDate = curr_time; 
                update_book_db();
                cout<<"This book is now issued by you :)\n";
            }
            return ; 
        }
    }
    cout<<"This book does not exists :(\n";
    return ;
}

void Profesor::Issue_Book(){
    int n = book_db.Book_DB.size();
    string input;
    cout<<"Enter the Title of the book: ";
    cin>>input;
    // cin.ignore(); getline(cin,input);
    for(int i=0;i<n;i++){
        if(book_db.Book_DB[i].Title==input){
            if(book_db.Book_DB[i].isIssued=="yes"){
                cout<<"This book is already issued :(\n";
            }
            else{
                book_db.Book_DB[i].isIssued = "yes";
                this->List_of_Books.push_back(book_db.Book_DB[i]);
                time_t curr_time = time(NULL);
                book_db.Book_DB[i].issuedDate = curr_time; 
                book_db.Book_DB[i].issuedBy = this->name;
                update_book_db();
                cout<<"This book is now issued by you :)\n";
            }
            return ; 
        }
    }
    cout<<"This book does not exists :(\n";
    return ;
}

void Student::Fine_amount(){
    int flag = 0, fine = 0;
    for(int i=0;i<book_db.Book_DB.size();i++){
        if(book_db.Book_DB[i].issuedBy==this->name){
            time_t curr_time = time(NULL);
            int nof_days = (curr_time - book_db.Book_DB[i].issuedDate)/(86400); 
            if(nof_days>30) {
                fine += (nof_days-30)*2;
                flag=1;
            }
        }
    }
    cout<<"Total fine is "<<fine<<"\n";
    this->fineAmount = fine;
    update_student_db();
    if(flag==0) cout<<"No fine present\n";
    return ;
}

void Student::Clear_fine_amount(){
    cout<<"Fine Amount of Rs. "<<this->fineAmount<<" has been cleared\n";
    this->fineAmount = 0;
    for(int i=0;i<book_db.Book_DB.size();i++){
        if(book_db.Book_DB[i].issuedBy==this->name){
            int issueDate = book_db.Book_DB[i].issuedDate;
            time_t curr_time = time(NULL);
            int nofdays = (curr_time - issueDate)/(86400);
            if(nofdays>30){
                book_db.Book_DB[i].issuedBy="";
                book_db.Book_DB[i].isIssued="no";
                book_db.Book_DB[i].issuedDate=-1;
            }   
        }
    }
    update_student_db();
    update_book_db();
}

void Profesor::Clear_fine_amount(){
    this->fineAmount = 0;
    for(int i=0;i<book_db.Book_DB.size();i++){
        if(book_db.Book_DB[i].issuedBy==this->name){
            int issueDate = book_db.Book_DB[i].issuedDate;
            time_t curr_time = time(NULL);
            int nofdays = (curr_time - issueDate )/(86400);
            if(nofdays>60){
                book_db.Book_DB[i].issuedBy="";
                book_db.Book_DB[i].isIssued="no";
                book_db.Book_DB[i].issuedDate=-1;
            }
        }
    }
    update_book_db();
    update_professor_db();
    cout<<"Fine Amount of "<<this->fineAmount<<"has been cleared\n";
}

void Profesor::Fine_amount(){
    int flag=0, fine = 0;
    for(int i=0;i<book_db.Book_DB.size();i++){
        if(book_db.Book_DB[i].issuedBy==this->name){
            time_t curr_time = time(NULL);
            int nof_days = (curr_time - book_db.Book_DB[i].issuedDate)/(86400); 
            if(nof_days>30) {
                fine += (nof_days-60)*5;
                cout<<book_db.Book_DB[i].Title<<" : Rs "<<fine;
                flag=1;
            }
        }
    }
    this->fineAmount = fine;
    update_student_db();
    if(flag==0) cout<<"No fine present\n";
    return ;
}

void User::Check_Availability(){
    string input;
    cout<<"Enter the Title of the book: ";
    cin>>input;
    // cin.ignore(); getline(cin,input);
    int n = book_db.Book_DB.size();
    for(int i=0;i<n;i++){
        if(book_db.Book_DB[i].Title==input){
            if(book_db.Book_DB[i].isIssued=="yes"){
                cout<<"This book is not available for issue :(\n";
            }
            else{
                cout<<"This book is available for issue :)\n";
            }
            return ; 
        }
    }
    cout<<"This book does not exists :(\n";
    return ;
}

void Librarian::check_what_issued(){
    int user_num;
    string name;
    cout<<"Press 1 for Student\nPress 2 for Profesor\n";
    cout<<"Waiting for the user to take input: ";
    cin>>user_num;
    while(user_num!=1 && user_num!=2){
        cout<<"Invalid input! Press either 1 or 2: ";
        cin>>user_num;
    }
    cout<<"Enter the name of the user to check the book he/she has issued till now\n";
    cout<<"Name: ";  cin>>name;
    if(user_num==1){
        int len = user_db.Student_DB.size();
        for(int i=0;i<len;i++){
            if(user_db.Student_DB[i].name==name){
                Student* temp = &user_db.Student_DB[i];
                int nofbooks = temp->List_of_Books.size();
                cout<<"The user has issued "<<nofbooks<<" book/s\n";
                for(int i=0;i<nofbooks;i++){
                    cout<<to_string(i+1)+". Book\t\t\t\t"<<"Title: "<<temp->List_of_Books[i].Title<<"\n\t\t";
                }
                return ;
            }
        }
        cout<<"The user named "<<name<<" does not exists"<<endl;
    }
    else{
        int len = user_db.Profesor_DB.size();
        for(int i=0;i<len;i++){
            if(user_db.Profesor_DB[i].name==name){
                Profesor* temp = &user_db.Profesor_DB[i];
                int nofbooks = temp->List_of_Books.size();
                cout<<"The user has issued "<<nofbooks<<" books\n";
                for(int i=0;i<nofbooks;i++){
                    cout<<to_string(i+1)+". Book\t\t\t\t"<<"Title: "<<temp->List_of_Books[i].Title<<"\n\t\t";
                    return;
                }
            }
        }
        cout<<"The user named "<<name<<" does not exists"<<endl;
    }
}

void Librarian::check_whom_issued(){
    string title;
    cout<<"Enter the Title of the book to find who has issued it\n";
    cout<<"Title: ";  cin>>title;
    int len = book_db.Book_DB.size();
    for(int i=0;i<len;i++){
        if(book_db.Book_DB[i].Title == title){
            Book* temp = &book_db.Book_DB[i];
            if(temp->issuedBy!="") cout<<"The book is issued by "<<temp->issuedBy<<endl;
            else cout<<"The book is not issued by anyone\n";
            return ;
        }
    }
    cout<<"There does not exists any book titled "<<title<<endl;
    return ;
}

void DisplayInputMsgs(){
    cout<<"\nTo see all the books in the library press 1\n";
    cout<<"To see all the books you own press 2\n";
    cout<<"To issue any book, press 3\n";
    cout<<"To check availability of any book, press 4\n";
    cout<<"To Show all the fine, press 5\n";
    cout<<"To Clear all the fine, press 6\n";
    cout<<"To Logout of the page, press 0\n\n";
    return ;
}

void DisplayInputMsgsforLibrarian(){
    cout<<"\nTo add a user press 1\n";
    cout<<"To update a user press 2\n";
    cout<<"To delete a user press 3\n";
    cout<<"To add a book press 4\n";
    cout<<"To update a book press 5\n";
    cout<<"To delete a book press 6\n";
    cout<<"To list down all books press 7\n";
    cout<<"To list down all users press 8\n";
    cout<<"To check which book is issued to which user press 9\n";
    cout<<"To check all the books issued to a particular user press 10\n";
    cout<<"To Logout from the system press 0\n\n";
    return ;
}

int TakingInputsforStudent(Student* student){
    string input;
    DisplayInputMsgs();
    cout<<"Waiting for the input: ";
    cin>>input;
    if(input=="0"){
        Logout();
        return -1;
    }
    else if(input=="1"){
        book_db.Display();
    }
    else if(input=="2"){
        student->Display_my_Books();
    }
    else if(input=="3"){
        student->Issue_Book();
    }
    else if(input=="4"){
        student->Check_Availability();
    }
    else if(input=="5"){
        student->Fine_amount();
    }
    else if(input=="6"){
        student->Clear_fine_amount();
    }
    return 0;
}

int TakingInputsforLibrarian(Librarian* lib){
    string input;
    DisplayInputMsgsforLibrarian();
    cout<<"Waiting for the input: ";
    cin>>input;
    int i,n=input.length(), caseinput;
    for(i=0;i<n;i++){
        if(isdigit(input[i])==false) break;  
    }
    if(i!=n){
        cout<<"Invalid Input\n";
        return 0;
    }
    caseinput = stoi(input);
    switch (caseinput){
        case 0:
            Logout();
            return -1;
            break;
        case 1:
            user_db.Add();
            break;
        case 2:
            user_db.Update();
            break;
        case 3:
            user_db.Delete();
            break;    
        case 4:
            book_db.Add();
            break;
        case 5:
            book_db.Update();
            break;
        case 6:
            book_db.Delete();
            break;
        case 7:
            book_db.Display();
            break;
        case 8:
            user_db.Display();
            break;       
        case 9:
            lib->check_whom_issued();
            break;
        case 10:
            lib->check_what_issued();
            break;
        default:
            cout<<"Invalid Input\n";
            break;
    }
    return 0;
}

int TakingInputsforProfesor(Profesor* profesor){
    string input;
    DisplayInputMsgs();
    cout<<"Waiting for the input: ";
    cin>>input;
    if(input=="0"){
        Logout();
        return -1;
    }
    else if(input=="1"){
        book_db.Display();
    }
    else if(input=="2"){
        profesor->Display_my_Books();
    }
    else if(input=="3"){
        profesor->Issue_Book();
    }
    else if(input=="4"){
        profesor->Check_Availability();
    }
    else if(input=="5"){
        profesor->Fine_amount();
    }
    else if(input=="6"){
        profesor->Clear_fine_amount();
    }
    return 0;
}

void HomePage_for_Student(Student* student){
    string input;
    cout<<"--------------------------HomePage--------------------------\n";
    cout<<"Welcome "<<student->name<<endl;
    int inp = TakingInputsforStudent(student);
    while(inp!=-1){
        inp = TakingInputsforStudent(student);
    }
    return;
}

void HomePage_for_Profesor(Profesor* profesor){
    string input;
    cout<<"--------------------------HomePage--------------------------\n";
    cout<<"Welcome "<<profesor->name<<endl;
    int inp = TakingInputsforProfesor(profesor);
    while(inp!=-1){
        inp = TakingInputsforProfesor(profesor);
    }
    return;
}

void HomePage_for_Librarian(Librarian* lib){
    string input;
    cout<<"--------------------------HomePage--------------------------\n";
    cout<<"Welcome "<<lib->name<<endl;
    int inp = TakingInputsforLibrarian(lib);
    while(inp!=-1){
        inp = TakingInputsforLibrarian(lib);
    }
    return;
}

void LoginPage(){
    string input;
    cout<<"\nTo Login as a Student press 1\n";
    cout<<"To Login as a Professor press 2\n";
    cout<<"To Login as a Librarian press 3\n";
    cout<<"To Exit the programme press 0\n";
    cout<<"Waiting for the input: ";
    cin>>input;
    cout<<endl;
    if(input=="0"){
        return ;
    }
    else if(input=="1"){
        LoginPage_for_Student();
    }
    else if (input=="2"){
        LoginPage_for_Profesor();
    }
    else if(input=="3"){
        LoginPage_for_Librarian();
    }
    else{
        cout<<"!Invalid Input!\nPlease enter valid input\n";
        LoginPage();
    }
    return ;
}

void LoginPage_for_Profesor(){
    string name,password;
    //Created Login Page
    cout<<"--------------------------Login-Page-for-Professor--------------------------\n";
    cout<<"Enter your name: ";
    cin>>name;
    int n = user_db.Profesor_DB.size() ;
    for(int i=0;i<n;i++){
        if(name == user_db.Profesor_DB[i].name){
            cout<<"Enter your password: ";
            cin>>password;
            while( password != user_db.Profesor_DB[i].password ){
                cout<<"Wrong Password\n";
                cout<<"Press 0 to go back\n";
                cout<<"Enter your password again: ";
                cin>>password; 
                if(password=="0") LoginPage() ;
            }
            cout<<"Login Succesfull\n";
            HomePage_for_Profesor(&user_db.Profesor_DB[i]);    
            return ;
        }
    }
    cout<<"No such user found\n";
    cout<<"Please Sign in again\n";
    LoginPage();
    return ;
}

void LoginPage_for_Librarian(){
    string name,password;
    //Created Login Page
    cout<<"--------------------------Login-Page-for-Librarian--------------------------\n";
    cout<<"Enter your name: ";
    cin>>name;
    int n = user_db.Librarian_DB.size() ;
    for(int i=0;i<n;i++){
        if(name == user_db.Librarian_DB[i].name){
            cout<<"Enter your password: ";
            cin>>password;
            while( password != user_db.Librarian_DB[i].password ){
                cout<<"Wrong Password\n";
                cout<<"Press 0 to go back\n";
                cout<<"Enter your password again: ";
                cin>>password; 
                if(password=="0") LoginPage() ;
            }
            cout<<"Login Succesfull\n";
            HomePage_for_Librarian(&user_db.Librarian_DB[i]);    
            return ;
        }
    }
    cout<<"No such user found\n";
    cout<<"Please Sign in again\n";
    LoginPage();
    return ;
}

void LoginPage_for_Student(){
    string name,password;
    //Created Login Page
    cout<<"--------------------------Login-Page-for-Student--------------------------\n";
    cout<<"Enter your name: ";
    cin>>name;
    // cin.ignore(); getline(cin,name);
    int n = user_db.Student_DB.size() ;
    for(int i=0;i<n;i++){
        if(name == user_db.Student_DB[i].name){
            cout<<"Enter your password: ";
            cin>>password;
            while( password != user_db.Student_DB[i].password ){
                cout<<"Wrong Password\n";
                cout<<"Press 0 to go back\n";
                cout<<"Enter your password again: ";
                cin>>password; 
                if(password=="0") LoginPage() ;
            }
            cout<<"Login Succesfull\n";
            HomePage_for_Student(&user_db.Student_DB[i]);    
            return ;
        }
    }
    cout<<"No such user found\n";
    cout<<"Please Sign in again\n";
    LoginPage();
    return ;
}

int main(){
    //Read all csv Data
    read_csv_files();
    Initialize_Database();
    LoginPage();
    return 0;
}