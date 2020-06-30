#include <bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

struct Workshop
{
    int start;
    int end;
    int dur;
};

bool operator<(const Workshop &x, const Workshop &y)
{
    return x.end < y.end;
}

struct Available_Workshops
{
    int n;
    Workshop *arr;
    Available_Workshops()
    {
        arr = new Workshop[n];
    }
};

Available_Workshops *initialize(int *start_time, int *duration, int n)
{
    Workshop *ws = new Workshop[n];

    for (int i = 0; i < n; i++)
    {
        ws[i].start = start_time[i];
        ws[i].end = start_time[i] + duration[i];
        ws[i].dur = duration[i];
    }

    Available_Workshops *ret = new Available_Workshops;
    ret->n = n;
    ret->arr = ws;

    return ret;
}

int CalculateMaxWorkshops(Available_Workshops *aw)
{
    int n = aw->n;
    Workshop *ws = new Workshop[n];
    ws = aw->arr;

    sort(ws, ws + n);

    int count = 0;

    for (int i = 0, j = 1; i < n and j < n; i++)
    {
        j = i + 1;
        while (ws[j].start <= ws[i].end and ws[j].end >= ws[i].start)
            j++;
        count++;
        i = j;
    }

    return count;
}

int main(int argc, char *argv[])
{
    freopen("input.txt", "r", stdin);
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int *start_time = new int[n];
    int *duration = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> start_time[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> duration[i];
    }

    Available_Workshops *ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
