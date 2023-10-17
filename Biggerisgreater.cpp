string biggerIsGreater(string w) {
  int i = w.size() - 2;
    while (i >= 0 && w[i] >= w[i + 1]) {
        i--;
    }
    
    if (i == -1) {
        return "no answer"; 
    }
    
    int j = w.size() - 1;
    while (w[j] <= w[i]) {
        j--;
    }

    char temp = w[i];
    w[i] = w[j];
    w[j] = temp;

    reverse(w.begin() + i + 1, w.end());
    
    return w;
}
