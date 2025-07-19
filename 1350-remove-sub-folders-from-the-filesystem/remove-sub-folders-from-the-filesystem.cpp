struct node{
    unordered_map<string, node *> child;
    bool isWord;
};
class Solution {
private:
    node *newNode(){
        node *temp = new node();
        temp->isWord = false;
        return temp;
    }
    void insert(node *root, string str){
        istringstream iss(str);
        string name;
        while(getline(iss, name, '/')){
            if(name.empty()) continue;
            if(root->child.find(name) == root->child.end()){
                root->child[name] = newNode();
            }
            root = root->child[name];
        }
        root->isWord = true;
    }
    
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        node *root = newNode();
        for(auto str : folder){
            insert(root, str);
        }
        vector<string> result;
        for (string& path : folder) {
            node* currentNode = root;
            istringstream iss(path);
            string folderName;
            bool isSubFolder = false;

            while (getline(iss, folderName, '/')) {
                if (folderName.empty()) continue;
                node* nextNode = currentNode->child[folderName];
                if (nextNode->isWord && iss.rdbuf()->in_avail() != 0) {
                    isSubFolder = true;
                    break; 
                }
                currentNode = nextNode;
            }
            if (!isSubFolder) ans.push_back(path);
        }
        return ans;
    }
};