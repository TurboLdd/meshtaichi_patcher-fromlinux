#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    std::string fn="./boxx.1.hex.elem";
    fstream in(fn, fstream::in);
    int n, m;
    in >> n;
    cout<<fn<<endl;
    cout<<"load"<<n<<endl;
    cout<<"load node"<<endl;
    if (fn.substr(fn.size() - 4) == "node") m = 3;//read coordinates
    cout<<"load face"<<endl;
    if (fn.substr(fn.size() - 4) == "face") m = 4;//face node
    cout<<"load elem"<<endl;//错误
    if (fn.substr(fn.size() - 3) == "ele") m = 8;//read the node of elements

    cout<<"load done"<<endl;
    for (char ch = in.get(); ch != '\n'; ch = in.get());//000000000000
    cout<<"jump"<<endl;
    std::vector<int> arr(n * m);
    for (int i = 0; i < n; i++) {
        cout<<i<<"line"<<endl;
        int _;
        in >> _;
        for (int j = 0; j < m; j++) {
            in >> arr[i * m + j];
        }
        for (char ch = in.get(); !in.eof() && ch != '\n'; ch = in.get());
    }
    cout<<"end for"<<endl;
    return 0;
}