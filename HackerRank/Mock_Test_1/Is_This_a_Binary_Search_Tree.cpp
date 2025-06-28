//https://www.hackerrank.com/contests/iitb-2025-26-mock-coding-test-1/challenges/is-binary-search-tree
/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/

//Uncomment the below code and run

// void walk(Node* x,vector<int> &v){
//         vector<int> u;
//         if(x->left){walk(x->left,u);}
//         u.push_back(x->data);
//         if(x->right){walk(x->right,u);}
//         v.insert(v.end(),u.begin(),u.end());
// }
// bool checkBST(Node* root) {
// 		vector<int> v;
//         walk(root,v);
//         bool b=true;
//         for(int i=0;i<int(v.size()-1);i++){
//             b=b&&(v[i]<v[i+1]);
//         }
//         return b;
// }