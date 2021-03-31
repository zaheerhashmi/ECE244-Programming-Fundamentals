#include <iostream>

using namespace std;

int main(int argc,char **argv)
{
    cout << "There are " << argc << " arguments given" << endl;
    for(int i=1;i<argc;++i)
        cout << "argv[" << i << "] = \"" << argv[i] << '"' << endl;
    return 0;
}
