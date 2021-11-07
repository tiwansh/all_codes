// Author : Anshuman Tiwari
// ----------- HEAPS USING ARRAYS --------------
#include<bits/stdc++.h>
using namespace std;

// Default macros
#define ll long long
#define ull unsigned long long

#define mini(a, b) a >= b ? b : a
#define maxi(a, b) a >= b ? a : b

#define pra(a, n) for(int I = 0;I < n;I++) cout<<a[I]<<" "
#define sca(a, n) for(int I = 0;I < n;I++) cin>>a[I]
#define sc1(a) scanf("%d",&a);
#define pr1(a) printf("%d ",a);
#define MODVAL 1000000007

// Default functions
ll gcd(ll a, ll b){
  if(b==0){
    return a;
  }
  return gcd(b, a % b);
}
ll lcm(ll a, ll b){
  ll lcm = ((a * b) / gcd(a, b));
  return lcm;
}
ll ncr_combination(int n, int r){
  if(r == 0 || r == n) return 1;
  //returns combinations n! / (r! * (n-r)!)
  ll num = 1;
  ll den = 1;
  r = min(n, n - r);
  // C(n, r) = C(n, n - r);
  while(r != 0){
    num *= n;
    den *= r;
    int gcd_both = gcd(num, den);
    num = num / gcd_both;
    den = den / gcd_both;
    n--;
    r--;
  }
  return num;
}
ll ModulusMultiplication(ll a, ll b, ll modval){
  ll result = 0;
  a = a % modval;
  while(b){
    // if b is odd, add a to result and mod
    if(b % 2 != 0){
      result = (result + a) % modval;
    }
    //add
    a = (2 * a) % modval;
    b = b / 2;
  }
  return result;
}

//Bit magic functions
int first_set_bit(int n){
  for(int I = 0;I < 32;I++){
    if(n & (1 << I)) return I + 1;
  }
  return -1;
}
bool is_kth_bit_set(int n, int k){
  if(n & (1 << k)) return true;
  return false;
}

// ----------Default DS-----------------
// Linked list
struct Node {
    int data;
    Node* next;
};
// Binary Search Tree
struct BSTNode{
  int data;
  BSTNode* left;
  BSTNode* right;
};
// Tree
struct TreeNode{
  int data;
  TreeNode *left;
  TreeNode *right;
};
//Heap using prority queue
priority_queue<int> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;
// Graphs
ll graph[1005][1005];
//------------Default DS ends------------


// -----------DS Functions --------------
// Linked list function
int getMiddle(Node *head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}
int getLength(Node *head){
    Node* slow = head;
    Node* fast = head;
    int count = 0;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        count++;
    }
    if(fast != NULL) return count * 2 + 1;
    else return count * 2;
}
Node* reverse(Node *head){
    Node *current = head;
    Node *prev = NULL, *next = NULL;
    while (current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    // head = prev;
    return head;
}

// BST functions
void inorderTraversal(BSTNode* root){
  if(root->left != NULL) inorderTraversal(root->left);
  cout<<root->data<<" ";
  if(root->right != NULL) inorderTraversal(root->right);
}
BSTNode *lowest_common_ancestor_bst(BSTNode *root, int n1, int n2){
  if(root == NULL){
    return NULL;
  }
  if(n1 > root->data && n2 > root->data) return lowest_common_ancestor_bst(root->right, n1, n2);
  if(n1 < root->data && n2 < root->data) return lowest_common_ancestor_bst(root->left, n1, n2);
  return root;
}
BSTNode *addNodeBST(BSTNode *root, int value_to_insert){
  // cout<<"Stuck";
  if(root == NULL){
    BSTNode *temp;
    temp = (BSTNode*)malloc(sizeof(BSTNode));
    temp->left = NULL;
    temp->data = value_to_insert;
    temp->right = NULL;
    return temp;
  }
  if(value_to_insert <= root->data){
    root->left = addNodeBST(root->left, value_to_insert);
  }
  else{
    root->right = addNodeBST(root->right, value_to_insert);
  }
  return root;
}

//Heap function


// Tree functions
void inorderTreeTraversal(TreeNode *root){
  if(root->left != NULL) inorderTreeTraversal(root->left);
  cout<<root->data<<" ";
  if(root->right != NULL) inorderTreeTraversal(root->right);
}
TreeNode *newTreeNode(int value_to_insert){
  TreeNode *temp;
  temp = (TreeNode*)malloc(sizeof(TreeNode));
  temp->left = NULL;
  temp->data = value_to_insert;
  temp->right = NULL;
  return temp;
}
int maxHeightOfTree(TreeNode *root){
  if(root == NULL) return 0;
  return max(maxHeightOfTree(root->left), maxHeightOfTree(root->right)) + 1;
}
int tree_diameter(TreeNode *root){
  if(root == NULL) return 0;
  int lheight = maxHeightOfTree(root->left);
  int rheight = maxHeightOfTree(root->right);
  // cout<<lheight<<" "<<rheight<<endl;
  return max(lheight + rheight + 1, max(tree_diameter(root->left), tree_diameter(root->right)));
}

// String functions
vector<string> split(string s, char c){
  vector<string> mv;
  int last = 0;
  for(int I = 0;I < s.size();I++){
    // Create the substring and push in the vector
    if(s[I] == c){
      mv.push_back(s.substr(last, I - last));
      last = I + 1;
    }
  }
  if(last < s.size()){
    mv.push_back(s.substr(last, s.size() - last));
  }
  return mv;
}
vector<string> get_all_substrings(string a){
  int n = a.size();
  vector<string> mv;
  for(int I = 0;I < n;I++){
    for(int J = 1;J <= n - I;J++){
        mv.push_back(a.substr(I, J));
    }
  }
  return mv;
}

//Heapsort using array/vetor functions
#define parent(a) (a / 2)
#define left(a) (a * 2) + 1
#define right(a) (a * 2) + 2
void heapify(int a[], int index, int n){
  int largest = index;
  int l = 2 * index + 1;
  int r = 2 * index + 2;
  if(l < n && a[l] > a[index]){
      largest = l;
  }
  if(r < n && a[r] > a[largest]){
      largest = r;
  }
  if(largest != index){

    int temp = a[largest];
    a[largest] = a[index];
    a[index] = temp;

    heapify(a, largest, n);
  }
}
void build_heap(int a[], int n){
  for(int I = (n / 2) - 1;I >= 0;I--){
    heapify(a, I, n);
  }
}

//Sorting Functions
void heapsort(int a[], int n){
  build_heap(a, n);
  for(int I = n - 1;I >= 0;I--){
    // swap the first and last and heapify
    int temp = a[I];
    a[I] = a[0];
    a[0] = temp;

    //heapify on the swapped number
    heapify(a, 0, I);
  }
}


//Graph functions
void dfs_visit(int visited[], int J, int n){
  cout<<J<<" ";
  visited[J] = 1;
  for(int I = 0;I < n;I++){
    if(graph[J][I] == 1 && visited[I] == 0){
      dfs_visit(visited, I, n);
    }
  }
}
void dfs(int visited[], int n){
  // visited[0] = 1;
  for(int I = 0;I < n;I++){
    if(visited[I] == 0){
      cout<<I<<" ";
      visited[I] = 1;
    }
    for(int J = 0;J < n;J++){
      if(graph[I][J] == 1 && visited[J] == 0){
        dfs_visit(visited, J, n);
      }
    }
  }
}
void bfs(int n, int starting_vertex){
  //insert the first node into queue
  int visited[n] = {0};
  queue<int> mq;
  // push the first element
  mq.push(starting_vertex);
  while(!mq.empty()){
    int curr_element = mq.front();
    visited[curr_element] = 1;
    mq.pop();
    cout<<curr_element<<" ";
    for(int I = 0 ;I < n;I++){
      if(graph[curr_element][I] == 1 && visited[I] == 0){
        visited[I] = 1;
        mq.push(I);
      }
    }
  }
}

bool sortFunc(const vector<int> &v1,const vector<int> &v2){
  //Sorting function used as 3rd parameter in sort() function to sort by 1st
  //column in a 2d vector
  return v1[0] < v2[0];
}
vector<vector<int>> kruskals(int vertices, int edges, vector<vector<int>> mv){
  //sort the vector by first column which is weight
  sort(mv.begin(), mv.end(), sortFunc);

  //Debugging : Check if the vector is sorted by the first column or not
  // for(int I = 0;I < mv.size();I++){
  //   for(int J = 0;J < 3;J++){
  //     cout<<mv[I][J]<<" ";
  //   }
  //   cout<<endl;
  // }
  map<int, set<int>> mm;
  for(int I = 0;I < vertices;I++){
    //push each element in the set
    set<int> inner;
    inner.insert(I);
    mm[I] = inner;
  }

  //define vector with final weight and edges
  vector<vector<int>> kruskal_result;
  for(int I = 0;I < mv.size();I++){
    //pick the edge one by one
    int weight = mv[I][0];
    int node1 = mv[I][1];
    int node2 = mv[I][2];

    // check if it creates a cycle or not
    if(mm[node1].find(node2) != mm[node1].end()){
      //cycle is present
      continue;
    }

    //Add the edge to kruskal_result if not forming a cycle
    kruskal_result.push_back(mv[I]);
    mm[node1].insert(mm[node2].begin(), mm[node2].end());
    mm[node2].insert(mm[node1].begin(), mm[node1].end());
  }
  //returns kruskals edges in weight - node1 - node2 manner
  return kruskal_result;
}
//------------DS Functions ends-------------
// Main code
int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    ll t, k, num, ans, n;
    int weight;
    vector<ll> a, b;
    string str;
    char ch;
    //N defines the nodes

return 0;
}