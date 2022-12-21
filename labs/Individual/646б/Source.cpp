#include <iostream>

using namespace std;

int main() {
  int n, maxa = 0, res = 0;

  cout << "Ïðîãðàììà äëÿ íàõîæäåíèÿ íàèáîëüøåãî çíà÷åíèÿ âñòðå÷àþùåãîñÿ â "
          "ïîñëåäîâàòåëüíîñòè"
       << endl;
  cout << "ïîñëå âûáðàñûâàíèÿ èç íåå âñåõ max(a1, ..., an)" << endl;
  cout << "---------------------------------" << endl;

  cout << "Ââåäèòå êîëè÷åñòâî ÷èñåë (n) >";
  cin >> n;
  int *a = new int[n];

  cout << "Ââåäèòå ÷èñëà (a): " << endl;
  for (int i = 0; i < n; i++) {
    cout << "a" << i + 1 << "= ";
    cin >> a[i];
    if (a[i] > maxa) {
      maxa = a[i];
    }
  }

  int count = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != maxa) {
      if (res < a[i]) {
        res = a[i];
      }
    }
  }
  cout << endl;

  delete[] a;

  cout << "Ðåçóëüòàò: " << res << endl;

  return 0;
}
