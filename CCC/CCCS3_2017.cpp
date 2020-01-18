/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: azumnanji
 *
 * Created on December 29, 2017, 12:32 PM
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int countingSort[2001];
int lengths [2001];

void readinput()
{
    cin >> n;
    
    memset(countingSort, 0, sizeof(countingSort));
    
    for (int i =0; i < n; i ++)
    {
        int l;
        cin >> l;
        countingSort[l]++;
    }
}

int find_number_boards_at_height(int height)
{
    memcpy(lengths, coutingSort, sizeof(lengths));
    
    int a = max(1, height-2000);
    int b = height - a;
    
    int num_of_boards = 0;
    
    while ( a <= height/2)
    {
        if (a==b)
        {
            int boards = lengths[a] / 2;
            lengths[a] -= boards * 2;
            
            num_of_boards += boards;
        }
        else
        {
            int boards = min(lengths[a], lengths[b]);
            lengths[a] -= boards;
            lengths[b] -= boards;
            
            num_of_boards += boards;
        }
        ++a;
        --b;
    }
    
    return num_of_boards;
}

int main()
{
    readinput();
    
    int max_boards = 0;
    int heights = 0;
    
    for (int i = 2; i <= 4000; i ++)
    {
        int boards = find_number_boards_at_height(i);
        
        if (boards > max_boards)
        {
            max_boards = boards;
            heights = 0;
        }
        if (boards == max_boards)
        {
            heights++;
        }
    }
    
    cout<<max_boards<<" "<<heights;
    return 0;
}

