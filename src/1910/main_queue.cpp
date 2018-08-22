#include <iostream>
#include <queue>
using namespace std;

int calculate (queue<int> wind)
{
        int result = 0;
        for (int i = 0; i < 3; i++) {
                result += wind.front();
                wind.pop();
        }
        return result;
}

int main() {
        int n, sum = 0, max=0, el, position=2, middle=2;
        queue<int> window;

        cin >> n;
        for (int i = 0; i < 3; i++) {
                cin >> el;
                window.push(el);
                max += el;
        }
        for (int i = 0; i < n-3; i++) {
                cin >> el;
                window.push(el);
                window.pop();
                sum = calculate(window);
                position++;
                if(sum > max) {
                        max = sum;
                        middle = position;
                }
        }
        cout << max << " " << middle;
        return 0;
}

