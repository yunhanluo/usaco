void pv(vector<int> v) {
  for (auto &i : v) {
    cout << i << " ";
  }
  cout << endl;
}

void ps(set<int> s) {
    for (auto &i : s) {
        cout << i << " ";
    }
    cout << endl;
}

void pa(int a[], int length) {
  for (int i=0; i<length; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
