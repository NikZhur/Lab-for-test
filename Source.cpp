#include <iostream>
#include <iomanip>
#include <time.h>
#include <chrono>
using namespace std;
using namespace chrono;

void menu() {
    cout << "������� 1, ���� ������ ������������ ���������� �������:\n";
    cout << "������� 2, ���� ������ ����� ������������ � ����������� ������� �������:\n";
    cout << "������� 3, ���� ������ ����� ������� �������� ����. � ���. ��������� �������, ������� ���� ���������, ������� ����� ����� ��������, � �� ����������:\n";
    cout << "������� 4, ���� ������ ������� ���������� ��������� � ��������������� �������, ������� ������ ���������� ����� a:\n";
    cout << "������� 5, ���� ������ ������� ���������� ��������� � ��������������� �������, ������� ������ ���������� ����� b:\n";
    cout << "������� 6, ���� ������ ������� ���������� � ���, ���� �� ��������� ������������� ����� � ��������������� ������� ����� �������� �����:\n";
    cout << "������� 7, ���� ������ ������� ���������� � ���, ���� �� ��������� ������������� ����� � ��������������� ������� ����� �������:\n";
    cout << "������� 8, ���� ������ �������� ������� �������� �������:\n";
    cout << "������� 9, ��� ��������� ���:\n";
    cout << "������� 0, ���� ������ ����� �� ���������:\n";
}
void menu2() {
    cout << "������� 1, ���� ������ ������������ bubble sort:\n";
    cout << "������� 2, ���� ������ ������������ shaker sort:\n";
    cout << "������� 3, ���� ������ ������������ comb sort:\n";
    cout << "������� 4, ���� ������ ������������ insert sort:\n";
    cout << "������� 5, ���� ������ ������������ quick sort:\n";
    cout << "������� 0, ���� ������ ������������ ����� � �������� ����:\n";
}

int bubble_sort(int Arr[], int N) {
    bool flag;
    for (int j = 0; j < N - 1; ++j) {
        flag = false;
        for (int i = 0; i < N - 1 - j; ++i) {
            if (Arr[i] > Arr[i + 1]) {
                swap(Arr[i], Arr[i + 1]);
                flag = true;
            }
        }
        if (flag == false) {
            break;
        }
    }
    return 0;
}

int shaker_sort(int Arr[], int N) {
    bool flag;
    for (int j = 0; j < N / 2; ++j) {
        flag = false;
        for (int i = j; i < N - 1 - j; ++i) {
            if (Arr[i] > Arr[i + 1]) {
                swap(Arr[i], Arr[i + 1]);
                flag = true;
            }
        }
        for (int k = N - j - 2; k >= j; --k) {
            if (Arr[k] < Arr[k - 1]) {
                swap(Arr[k], Arr[k - 1]);
                flag = true;
            }
        }
        if (flag == false) {
            break;
        }
    }
    return 0;
}

int comb_sort(int Arr[], int N) {
    int swap;
    float k = 1.247, S = N - 1;
    int count = 0;
    while (S >= 1) {
        for (int i = 0; i + S < N; i++) {
            if (Arr[i] > Arr[int(i + S)]) {
                swap = Arr[int(i + S)];
                Arr[int(i + S)] = Arr[i];
                Arr[i] = swap;
            }
        }
        S /= k;
    }
    while (true) {
        for (int i = 0; i < N - 1; i++) {
            if (Arr[i] > Arr[i + 1]) {
                swap = Arr[i + 1];
                Arr[i + 1] = Arr[i];
                Arr[i] = swap;
            }
            else count++;
        }
        if (count == N - 1)
            break;
        else
            count = 0;
    }
    return 0;
}

int insert_sort(int Arr[], int N) {
    int perem, elem;
    for (int i = 1; i < N; ++i) {
        perem = Arr[i];
        elem = i;
        for (int j = i - 1; j >= 0 && Arr[j] > perem; --j) {
            Arr[j + 1] = Arr[j];
            elem = j;
        }
        Arr[elem] = perem;
    }
    return 0;
}

void quicksort(int* arr, int end, int begin) {
    int mid;
    int f = begin;
    int l = end;
    mid = arr[(f + l) / 2];
    while (f < l)
    {
        while (arr[f] < mid) f++;
        while (arr[l] > mid) l--;
        if (f <= l)
        {
            swap(arr[f], arr[l]);
            f++;
            l--;
        }
    }
    if (begin < l) quicksort(arr, l, begin);
    if (f < end) quicksort(arr, end, f);
}

void search_elem_sort(int Arr[]) {
    int min_elem, max_elem;
    min_elem = Arr[0];
    max_elem = Arr[99];
    cout << "���. �������:  " << min_elem << '\t' << "����. �������:  " << max_elem;
}

void search_elem(int Arr[], int N) {
    int min_elem2 = Arr[0], max_elem2 = Arr[0];
    for (int i = 1; i < N; i++) {
        if (Arr[i] < min_elem2) {
            min_elem2 = Arr[i];
        }
        if (Arr[i] > max_elem2) {
            max_elem2 = Arr[i];
        }
    }
    cout << "���. �������:  " << min_elem2 << '\t' << "����. �������:  " << max_elem2;
}

void average_value_sort(int Arr[], int N) {
    int min_elem, max_elem, average;
    min_elem = Arr[0];
    max_elem = Arr[99];
    if (((min_elem + max_elem) % 2 == 1) || ((min_elem + max_elem) % 2 == -1)) {
        average = (min_elem + max_elem) / 2 + ((min_elem + max_elem) % 2);
    }
    else {
        average = (min_elem + max_elem) / 2;
    }
    cout << "��. ��������:  " << average << "\n";
    int count = 0;
    cout << "������� ���������, ������ ��. ��������:  ";
    for (int i = 0; i < N; i++) {
        if (Arr[i] == average) {
            cout << i << '\t';
            count++;
        }
    }
    cout << '\n' << "���������� ���������, ������ ��. ����:  " << count;
}

void average_value(int Arr[], int N) {
    int min_elem2 = Arr[0], max_elem2 = Arr[0], average2;
    for (int i = 1; i < N; i++) {
        if (Arr[i] < min_elem2) {
            min_elem2 = Arr[i];
        }
        if (Arr[i] > max_elem2) {
            max_elem2 = Arr[i];
        }
    }
    if ((min_elem2 + max_elem2) % 2 == 1 || ((min_elem2 + max_elem2) % 2 == -1)) {
        average2 = (min_elem2 + max_elem2) / 2 + ((min_elem2 + max_elem2) % 2);
    }
    else {
        average2 = (min_elem2 + max_elem2) / 2;
    }
    cout << "��. ��������:  " << average2 << "\n";
    int count2 = 0;
    cout << "������� ���������, ������ ��. ��������:  ";
    for (int i = 0; i < N; i++) {
        if (Arr[i] == average2) {
            cout << i << '\t';
            count2++;
        }
    }
    cout << '\n' << "���������� ���������, ������ ��. ����:  " << count2;
}

void min_numbers(int Arr[], int N) {
    int a;
    cout << "������� ����� a:  ";
    cin >> a;
    int count = 0;
    while (Arr[count] < a && count < N) {
        count++;
    }
    cout << "���������� ���������:  " << count << "\n\n";
}

void max_numbers(int Arr[], int N) {
    int b;
    cout << "������� ����� b:  ";
    cin >> b;
    int i = N - 1;
    int count = 0;
    while (Arr[i] > b && i >= 0) {
        count++;
        i--;
    }
    cout << "���������� ���������:  " << count << "\n\n";
}

int binarySearch(int Arr[], int value, int start, int end) {
    if (end >= start) {
        int mid = start + (end - start) / 2;

        if (Arr[mid] == value) {
            return mid;
        }

        if (Arr[mid] > value) {
            return binarySearch(Arr, value, start, mid - 1);
        }

        return binarySearch(Arr, value, mid + 1, end);
    }

    return -1;
}

void search_value(int Arr[], int value, int N) {
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;
    start = steady_clock::now();
    bool flag = false;
    for (int i = 0; i < N; i++) {
        if (Arr[i] == value) {
            end = steady_clock::now();
            cout << "����� ������� ����, ��� ������: " << i;
            flag = true;
            break;
        }
    }
    if (flag == false) {
        end = steady_clock::now();
        cout << "������ �������� ���";
    }
    cout << "\n\n";
    result = duration_cast<nanoseconds>(end - start);
    cout << "����� ����������:  ";
    cout << result.count() << " ��";
    cout << "\n\n";
}

void swapElem(int Arr[], int ind1, int ind2) {
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;
    start = steady_clock::now();
    int perem = Arr[ind1];//
    Arr[ind1] = Arr[ind2];
    Arr[ind2] = perem;//
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << "����� ����������:  ";
    cout << result.count() << " ��";
    cout << "\n\n";
}



void element_reduction(int Arr[], int N) {
    int num;
    cout << "������� �����, �� ������� ������ ��������� �������� �������� �������:  ";
    cin >> num;
    cout << "\n\n";
    for (int i = 1; i < N; i += 2) {
        Arr[i] -= num;
    }
}

void element_multiplication(int Arr[], int N) {
    int num2;
    cout << "�����, �� ������� ���������� ���������:\n";
    for (int i = 1; i < N; i += 2) {
        num2 = rand() % 9 + 1;
        cout << num2 << " ";
        Arr[i] *= num2;
    }
}

void sum_elem(int Arr[], int N) {
    int count = 0, count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0, count7 = 0, count8 = 0, count9 = 0;
    for (int i = 0; i < N; i++) {
        if (Arr[i] % 2 == 0 && Arr[i] % 3 == 0 && Arr[i] % 4 == 0 && Arr[i] % 5 == 0 && Arr[i] % 6 == 0 && Arr[i] % 7 == 0 && Arr[i] % 8 == 0 && Arr[i] % 9 == 0) {
            count++;
            cout << Arr[i] << "\n";
        }
        if (Arr[i] % 1 == 0) {
            count1++;
        }
        if (Arr[i] % 2 == 0) {
            count2++;
        }
        if (Arr[i] % 3 == 0) {
            count3++;
        }
        if (Arr[i] % 4 == 0) {
            count4++;
        }
        if (Arr[i] % 5 == 0) {
            count5++;
        }
        if (Arr[i] % 6 == 0) {
            count6++;
        }
        if (Arr[i] % 7 == 0) {
            count7++;
        }
        if (Arr[i] % 8 == 0) {
            count8++;
        }
        if (Arr[i] % 9 == 0) {
            count9++;
        }
    }
    cout << "���������� �����, ������� ������ ������� �� 1, 2, 3, 4, 5, 6, 7, 8, 9: " << count << "\n";
    cout << "���������� �����, ������� ������ ������� �� 1: " << count1 << "\n";
    cout << "���������� �����, ������� ������ ������� �� 2: " << count2 << "\n";
    cout << "���������� �����, ������� ������ ������� �� 3: " << count3 << "\n";
    cout << "���������� �����, ������� ������ ������� �� 4: " << count4 << "\n";
    cout << "���������� �����, ������� ������ ������� �� 5: " << count5 << "\n";
    cout << "���������� �����, ������� ������ ������� �� 6: " << count6 << "\n";
    cout << "���������� �����, ������� ������ ������� �� 7: " << count7 << "\n";
    cout << "���������� �����, ������� ������ ������� �� 8: " << count8 << "\n";
    cout << "���������� �����, ������� ������ ������� �� 9: " << count9 << "\n\n";
}


int main() {
    setlocale(LC_ALL, "Russian");
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;
    srand(time(NULL));
    cout << "�������� ������:\n";
    const int N = 100;
    int A[N];
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 199 - 99;
        cout << A[i] << " ";
    }
    cout << "\n\n";

    int B[N];
    for (int i = 0; i < N; i++) {
        B[i] = A[i];
    }

    int C[N];
    for (int i = 0; i < N; i++) {
        C[i] = A[i];
    }

    int D[N];
    for (int i = 0; i < N; i++) {
        D[i] = A[i];
    }

    int E[N];
    for (int i = 0; i < N; i++) {
        E[i] = A[i];
    }

    int F[N];
    for (int i = 0; i < N; i++) {
        F[i] = A[i];
    }

    int G[N];
    for (int i = 0; i < N; i++) {
        G[i] = A[i];
    }

    int H[N];
    for (int i = 0; i < N; i++) {
        H[i] = A[i];
    }

    int I[N];
    for (int i = 0; i < N; i++) {
        I[i] = A[i];
    }

    int ends = N - 1, begin = 0;
    menu();
    int i2;
    cin >> i2;
    cout << "\n";
    while (i2 != 0) {
        switch (i2) {
        case 0:
            exit(0);
        case 1:
            menu2();
            int i;
            cin >> i;
            switch (i) {
            case 1:
                start = steady_clock::now();
                bubble_sort(A, N);
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << "\n";
                cout << "����� ����������:  ";
                cout << result.count() << " ��";
                cout << "\n\n";
                cout << "��������������� ������:\n";
                for (int i = 0; i < N; ++i) {
                    cout << A[i] << " ";
                }
                cout << "\n\n";
                menu();
                break;
            case 2:
                start = steady_clock::now();
                shaker_sort(B, N);
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << "\n";
                cout << "����� ����������:  ";
                cout << result.count() << " ��";
                cout << "\n\n";
                cout << "\n" << "��������������� ������:\n";
                for (int i = 0; i < N; ++i) {
                    cout << B[i] << " ";
                }
                cout << "\n\n";
                menu();
                break;
            case 3:
                start = steady_clock::now();
                comb_sort(C, N);
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << "\n";
                cout << "����� ����������:  ";
                cout << result.count() << " ��";
                cout << "\n\n";
                cout << "\n" << "��������������� ������:\n";
                for (int i = 0; i < N; i++)
                {
                    cout << C[i] << " ";
                }
                cout << "\n\n";
                menu();
                break;
            case 4:
                start = steady_clock::now();
                insert_sort(D, N);
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << "\n";
                cout << "����� ����������:  ";
                cout << result.count() << " ��";
                cout << "\n\n";
                cout << "\n" << "��������������� ������:\n";
                for (int i = 0; i < N; ++i) {
                    cout << D[i] << " ";
                }
                cout << "\n\n";
                menu();
                break;
            case 5:
                start = steady_clock::now();
                quicksort(E, ends, begin);
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << "\n";
                cout << "����� ����������:  ";
                cout << result.count() << " ��";
                cout << "\n";
                cout << "\n" << "��������������� ������:\n";
                for (int i = 0; i < N; i++)
                    cout << E[i] << " ";
                cout << "\n\n";

                menu();
                break;
            case 0:
                cout << "\n";
                menu();
                break;
            default:
                cout << "������� ������������ �����";
                cout << "\n\n";
                menu();
            }
            break;
        case 2:
            quicksort(I, ends, begin);
            start = steady_clock::now();
            search_elem_sort(I);
            end = steady_clock::now();
            result = duration_cast<nanoseconds>(end - start);
            cout << "\n\n";
            cout << "����� ����������:  ";
            cout << result.count() << " ��";
            cout << "\n\n";

            start = steady_clock::now();
            search_elem(F, N);
            end = steady_clock::now();
            result = duration_cast<nanoseconds>(end - start);
            cout << "\n\n";
            cout << "����� ����������:  ";
            cout << result.count() << " ��";
            cout << "\n\n";
            menu();
            break;
        case 3:
            quicksort(I, ends, begin);
            start = steady_clock::now();
            average_value_sort(I, N);
            end = steady_clock::now();
            result = duration_cast<nanoseconds>(end - start);
            cout << "\n\n";
            cout << "����� ����������:  ";
            cout << result.count() << " ��";
            cout << "\n\n";

            start = steady_clock::now();
            average_value(F, N);
            end = steady_clock::now();
            result = duration_cast<nanoseconds>(end - start);
            cout << "\n\n";
            cout << "����� ����������:  ";
            cout << result.count() << " ��";
            cout << "\n\n";
            menu();
            break;
        case 4:
            quicksort(I, ends, begin);
            min_numbers(I, N);
            cout << "\n\n";
            menu();
            break;
        case 5:
            quicksort(I, ends, begin);
            max_numbers(I, N);
            cout << "\n\n";
            menu();
            break;
        case 6:
            quicksort(I, ends, begin);
            int value, res;
            cout << "������� �����:  ";
            cin >> value;
            cout << "\n";
            start = steady_clock::now();
            res = binarySearch(I, value, 0, N - 1);
            end = steady_clock::now();
            result = duration_cast<nanoseconds>(end - start);
            if (res == -1) {
                cout << "������ �������� ���\n\n";
            }
            else {
                cout << "����� ������� ����, ��� ������: " << res << "\n\n";
            }
            cout << "����� ����������:  ";
            cout << result.count() << " ��";
            cout << "\n\n";
            menu();
            break;
        case 7:
            quicksort(I, ends, begin);
            int value2;
            cout << "������� �����:  ";
            cin >> value2;
            cout << "\n";
            search_value(I, value2, N);
            cout << "\n\n";
            menu();
            break;
        case 8:
            quicksort(G, ends, begin);
            cout << "�������� ������:\n";
            for (int i = 0; i < N; i++) {
                cout << G[i] << " ";
            }
            cout << "\n\n";
            int ind1, ind2;
            cout << "������� ������ ���������:\n";
            cin >> ind1 >> ind2;
            cout << "\n";
            swapElem(G, ind1, ind2);
            cout << "������ ����� ���������:\n";
            for (int i = 0; i < N; i++) {
                cout << G[i] << " ";
            }
            cout << "\n\n";
            menu();
            break;
        case 9:
            cout << "�������� ������:\n";
            for (int i = 0; i < N; i++) {
                cout << H[i] << " ";
            }
            cout << "\n\n";
            element_reduction(H, N);
            cout << "���������� ����������:\n";
            for (int i = 0; i < N; i++) {
                cout << H[i] << " ";
            }
            cout << "\n\n";
            element_multiplication(H, N);
            cout << "\n\n";
            cout << "���������� ���������:\n";
            for (int i = 0; i < N; i++) {
                cout << H[i] << " ";
            }
            cout << "\n\n";
            sum_elem(H, N);
            menu();
            break;
        default:
            cout << "������� ������������ �����";
            cout << "\n\n";
            menu();
        }
        cin >> i2;
        cout << "\n";
    }
    return 0;
}