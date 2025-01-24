#include<bits/stdc++.h>
using namespace std;

class Student{
    public:            // if access modifier is not given then it will be automatially private
        string name;
        int roll_num;
        float marks;

        Student(string name, int roll_num, float marks){  // constructor 
            // this->name = name;
            // this->roll_num = roll_num;
            // this->marks = marks;

            (*this).name = name;         // this is the pointer to the class itself in which i am writting 
            (*this).roll_num = roll_num;
            (*this).marks = marks;

            // name = name;            // this is wrong because the name is same and we can't do this
            // roll_num = roll_num;
            // marks = marks;
        }

        void display(){
            cout<<"Name: "<<name<<endl;
            cout<<"roll_num: "<<roll_num<<endl;
            cout<<"marks: "<<marks<<endl;
            cout<<endl;
        }
};

void change(Student *s){   // it should be passed by reffernce 
    s->name = "Coder";
}
// void change(Student &s){   // it should be passed by reffernce 
//     s.name = "Coder";
// }

int main(){

    Student s1("Piyush",5295,91.22);

    // s1.display();
    // change(&s1);     
    // s1.display();

    // Student *ptr = &s1;  // pointer to the object s1 of class Student
    // ptr->name = "Piyush Goyal";    
    // // (*ptr).name = "Piyush Goyal";   // paranthesis are must
    // s1.display();

    Student *s = new Student("Abcdef",123,455.6);  // dynamic memory allocation
    s->display();
    change(s);
    s->display();

    return 0;
}