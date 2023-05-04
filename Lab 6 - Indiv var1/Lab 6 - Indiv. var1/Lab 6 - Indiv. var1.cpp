#include <iostream>
#include <cassert>
#include <string>

struct Student;
struct Professor;

struct Person
{
public:
    virtual ~Person()
    {}
};





struct Vizitor //pattern Vizitor
{
public:
    virtual ~Vizitor()
    { }
    virtual std::string vizitstudent(Student) = 0;
    virtual std::string vizitprofessor(Professor) = 0;
};





struct Student :
    public Person
{
public:
    Student(std::string fio, int nz)
        : fio_(fio), nz_(nz)
    {}

    ~Student()
    {}

    std::string name() const
    {
        return fio_;
    } // чтение левого операнда

    int zach() const
    {
        return nz_;
    } // чтение правого операнда

    std::string vizit(Vizitor* viz) const
    {
        return viz->vizitstudent(*this);
    }
private:
    std::string fio_;
    int nz_;
};





struct Professor :
    public Person
{
public:
    Professor(std::string fio, std::string kafedra) : fio_(fio), kafedra_(kafedra)
    {}

    std::string name()
    {
        return fio_;
    }

    std::string kafed()
    {
        return kafedra_;
    }

    ~Professor()
    {}

    std::string vizit(Vizitor* viz) const
    {
        return viz->vizitprofessor(*this);
    }
private:
    std::string fio_;
    std::string kafedra_;
};





struct Session : Vizitor
{
    std::string vizitstudent(Student student)
    {
        return "Student " + student.name() + " cdayet ekzameny";
    }

    std::string vizitprofessor(Professor professor)
    {
        return "Professor " + professor.name() + " prinimaet ekzameny";
    }
};





struct Holidays : Vizitor
{
    std::string vizitstudent(Student student)
    {
        return "Student " + student.name() + " otdyxaet";
    }

    std::string vizitprofessor(Professor professor)
    {
        return "Professor " + professor.name() + " yxodit v otpusk";
    }
};





int main()
{
    Student andrey("Andrey Arkadiev Artemov", 1);
    Student boris("Boris Hren Popadesh", 2);
    Professor groznyi("Ivan Ivanovich Groznyi", "Kafedra istoricheskih nauk");
    Professor dytlov("Gennady Nicolaevich Dytlov", "Kafedra matematiki");
    Session sessiy;
    Holidays holiday;
    std::cout << andrey.vizit(&sessiy) << std::endl;
    std::cout << andrey.vizit(&holiday) << std::endl;
    std::cout << boris.vizit(&sessiy) << std::endl;
    std::cout << boris.vizit(&holiday) << std::endl;
    std::cout << groznyi.vizit(&sessiy) << std::endl;
    std::cout << groznyi.vizit(&holiday) << std::endl;
    std::cout << dytlov.vizit(&sessiy) << std::endl;
    std::cout << dytlov.vizit(&holiday) << std::endl;
}