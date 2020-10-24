#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long

#define QUICK                       \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cerr.tie(NULL);
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define t_start auto start = chrono::high_resolution_clock::now();
#define t_stop                                                                     \
  auto stop = chrono::high_resolution_clock::now();                                \
  ld duration = chrono::duration_cast<chrono::microseconds>(stop - start).count(); \
  duration *= 1e-6;                                                                \
  cerr << fixed << duration << setprecision(9) << "\n";
#define deb(x) cerr << #x << "=" << x << "\n"
#define deb2(x, y) cerr << #x << "=" << x << ", " << #y << "=" << y << "\n"
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))

// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node
{
  int data;
  struct Node *next;
  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T, i, n, l, firstdata;
  cin >> T;
  while (T--)
  {

    struct Node *head = NULL, *tail = NULL;
    cin >> n;
    // taking first data of LL
    cin >> firstdata;
    head = new Node(firstdata);
    tail = head;
    // taking remaining data of LL
    for (i = 1; i < n; i++)
    {
      cin >> l;
      tail->next = new Node(l);
      tail = tail->next;
    }
    cout << isPalindrome(head) << endl;
  }
  return 0;
}

// } Driver Code Ends

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
/*You are required to complete this method */
bool isPalindrome(Node *head)
{
  Node *p = head, *q = head, *start = NULL;
  while (p != NULL)
  { //breaking the list from middle excluding middle
    if (p->next == NULL)
    { //conditon when odd elements
      start = q;
      break;
    }
    if (p->next->next == NULL)
    { //condition when even elements
      start = q->next;
      q->next = NULL;
      break;
    }
    p = p->next->next;
    q = q->next;
  }
  // cerr<<start->data<<"\n";
  q = NULL;
  while (start != NULL)
  { //for reversing the second part of list
    p = start->next;
    start->next = q;
    q = start;
    start = p;
  }
  // while(q!=NULL){
  //   cerr<<q->data<<"\n";
  //   q=q->next;
  // }
  while (q != NULL)
  { //finally comparing both the lists
    if (head->data != q->data)
    {
      return 0;
    }
    head = head->next;
    q = q->next;
  }
  return 1;
}
