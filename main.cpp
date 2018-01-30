#include <iostream>
#include <cstdlib>

using namespace std;

const int StudentCount = 20;

int A = 0x41;

class Student
{
    public:
        Student *lentTo;
        string Name;
        Student(string name) : Name(name) { }
        void LentTo(Student *_lentTo) { lentTo = _lentTo; cout << (*this).Name << "->" << ((*this).lentTo == this ? "'None'" : (*_lentTo).Name) << endl; }
};

int main()
{
    Student *Classroom[StudentCount];

    // Initialize Students
    for (int i = 0; i < StudentCount; i++)
    {
        char _str[1];
        _str[0] = i + A;
        Classroom[i] = new Student(_str);
    }

    // Define who lent to whom
    for (int i = 0; i < StudentCount; i++)
    {
        int lend = (rand() % StudentCount);
        (*Classroom[i]).LentTo(Classroom[lend]);
    }

    cout << endl; // Divide outputs

    // Calculate who owes to whom
    for (int i = 0; i < StudentCount; i++)
    {
        Student *current = Classroom[i];

        while (true)
        {
            if (current == nullptr) break;;
            if ((*current).lentTo == nullptr) break;
            if ((*current).lentTo == current) { (*current).lentTo = nullptr; break; }

            current = (*current).lentTo;
        }

        (*Classroom[i]).lentTo = current;
    }

    // Announce results
    for (int i = 0; i < StudentCount; i++)
    {
        Student *current = Classroom[i];
        if ((*current).lentTo == nullptr) continue;

        cout << (*(*current).lentTo).Name << " owes to " << (*current).Name << endl;
    }

    return 0;
}