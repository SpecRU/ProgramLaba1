#include "Stack.cpp"

using namespace std;

int main() {
    try {
        cout << "\n TEST 1: \n";
        Stack<int> S;
        S.push(123);
        S.push(456);

        int a = 7;
        S.swap(a);
        cout << S.pop() << endl << a << endl << S << "\n";

        cout << "\n TEST 2: \n";
        Stack<double> S1;
        S1.push(1.23);
        S1.push(4.56);
        S1.top(6.78);
        cout << S1.check_pop() << endl << S1 << "\n";

        cout << "\n TEST 3: \n";
        Stack<string> S2;
        S2.push("String test");
        S2.clear();
        S2.push("String test after clear");
        cout << S2 << "\n";

        cout << "\n TEST 4: \n";
        Stack<string> S3(S2);
        cout << S3 << " - copied" << "\n";

        cout << "\n TEST 5: \n";
        if (S2 == S3) cout << S3 << " - equal test" << "\n";

        cout << "\n TEST 6: \n";
        Stack<int> S4;
        S4.push(80085);
        if (S != S4) cout << S4;
        cout << " - not equal test" << "\n";

        cout << "\n TEST 7: \n";
        Stack<int> S5;
        S5.push(1);
        S5.push(2);
        S5 >> 3;
        S5 << 2;
        cout << S5 << "\n";
    }
    catch (const char* msg) {
        cout << msg;
    }
}