//https://en.cppreference.com/w/cpp/algorithm.html?authuser=0
//https://www.geeksforgeeks.org/cpp/iterators-c-stl/

#include <iostream>
#include <array>

using namespace std;

void main0()
{
    int arr[10] = {20, 50, -10, -40, 80, -30, 70, 55, 75, 5};
    vector<int> vettore = std::vector<int>(arr, arr + 10);
    std::sort(vettore.begin(), vettore.end());
    //vector<int>::iterator;
    int maggioriDi10 = 0;
    for (vector<int>::iterator it = vettore.begin(); it != vettore.end(); ++it)
    {
        if (*it > 10)
            maggioriDi10++;
    }

    int multipliDi10 = count_if(vettore.begin(), vettore.end(), [](int x) { return x % 10 == 0; });

    bool tuttiNonNegativi = all_of(vettore.begin(), vettore.end(),[](int x) { return x >= 0; });

    cout << endl << "[0] Vettore - divisibili per 10: " << multipliDi10 << " - tutti non negativi: " <<tuttiNonNegativi;
}

void main1()
{
    int arr[10] = {15, -3, 22, -8, 7, 0, 14, -1, 9, 30};
    vector<int> v = std::vector<int>(arr, arr + 10);

    auto it = find_if(v.begin(), v.end(),
                  [](int x) { return x < 0; });

    if (it != v.end())
        cout << "Primo valore negativo: " << *it << endl;
    else
        cout << "Nessun valore negativo" << endl;


    // Rimuovi valori negativi
    v.erase(remove_if(v.begin(), v.end(),
                      [](int x) { return x < 0; }),
            v.end());

    cout<<endl;
    for (int elemento : v)
    {
        cout<<elemento<<"\t";
    }
}

void main2()
{
    vector<int> v = {5, 18, 21, 40, 7, 9, 60, 11, 3, 100, 8, 2};

    // Valore > 50
    auto it = find_if(v.begin(), v.end(),
                      [](int x) { return x > 50; });

    if (it != v.end())
        cout << "Primo valore > 50: " << *it << endl;
    else
        cout << "Nessun valore > 50" << endl;

    // Rimuovi valori dispari
    v.erase(remove_if(v.begin(), v.end(),
                      [](int x) { return x % 2 != 0; }),
            v.end());

    cout << "Vettore finale: ";
    for (int x : v) cout << x << " ";
    cout << endl;
}

void main3()
{
    vector<int> v = {-5, -10, 20, 25, -30, 40, 0, -1, 60, 7};

    bool esisteNonNegativo = any_of(v.begin(), v.end(),
                                    [](int x) { return x >= 0; });

    cout << "Esiste valore non negativo? "
         << (esisteNonNegativo ? "SI" : "NO") << endl;

    auto it = find_if(v.begin(), v.end(),
                      [](int x) { return x > 30; });

    if (it != v.end())
        cout << "Primo valore > 30: " << *it << endl;
    else
        cout << "Nessun valore > 30" << endl;

    // rimuovi valori < 0
    v.erase(remove_if(v.begin(), v.end(),
                      [](int x) { return x < 0; }),
            v.end());

    // Ordina crescente
    sort(v.begin(), v.end());

    cout << "Vettore finale ordinato: ";
    for (int x : v) cout << x << " ";
    cout << endl;
}

int main()
{
    int numEsercizio = 1;

    switch (numEsercizio)
    {
        case 0:
            main0();
            break;
        case 1:
            main1();
            break;
        case 2:
            main2();
            break;
        case 3:
            main3();
            break;
    }

    return 0;
}