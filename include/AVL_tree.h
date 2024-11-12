#ifndef AVL_TREE_H
#define AVL_TREE_H

struct Node{
    int key;
    int bal;
    Node* l, *r;
};

void LLturn(Node* root, bool operation){ //operation = true - insert, false - delete
    Node* buf;
    int tempBal;
    buf = root->l;
    root->l = buf->r;
    buf->r = root;
    if(operation){
        root->bal = 0;
        buf->bal = 0;
    }
    else{
        tempBal = buf->bal;
        if (tempBal == 0){
            root->bal = -1;
            buf->bal = 1;
        }else{
            root->bal = 0;
            buf->bal = 0;
        }
    }
    root = buf;
}

void LRturn(Node* root, bool operation){
    Node* buf1, *buf2;
    buf1 = root->l;
    buf2 = buf1->r;
    buf1->r = buf2->l;
    buf2->l = buf1;
    buf1->l = buf2->r;
    buf2->r = root;
    if (buf2->bal == -1){
        root->bal = 1;
    }
    else{
        root->bal = 0;
    }
    if (buf2->bal == 1){
        buf1->bal = -1;
    }else{
        buf1->bal = 0;
    }
    root = buf2;
    if (operation){
        root->bal = 0;
    }else{
        buf2->bal = 0;
    }
}

void RRturn(Node* root, bool operation){
    Node* buf;
    int tempBal;

    buf = root->r;
    root->r = buf->l;
    buf->l = root;
    
    if (operation){
        root->bal = 0;
        buf->bal = 0;
    }
    else{
        tempBal = buf->bal;
        if (tempBal == 0){
            root->bal = 1;
            buf->bal = -1;
        }
        else{
            root->bal = 0;
            buf->bal = 0;
        }
    }

    root = buf;
}

void RLturn(Node* root, bool operation){
    Node* buf1;
    Node* buf2;
    int tempBal2;
    
    buf1 = root->r;
    buf2 = buf1->l;
    tempBal2 = buf2->bal;
    buf1->l = buf2->r;
    buf2->r = buf1;
    root->r = buf2->l;
    buf2->l = root;

    if (tempBal2 == 1){
        root->bal = -1;
    }
    else{
        root->bal = 0;
    }
    if (tempBal2 == -1){
        buf1->bal = 1;
    }else{
        buf1->bal = 0;
    }
    
    root = buf2;

    if(operation){
        root->bal = 0;
    }
    else{
        buf2->bal = 0;
    }
}

void insertHelp(int val, Node* root, bool h){
    if (root == NULL){
        root = new Node;
        h = true;
        root->key = val;
        root->bal = 0;
        root->l = NULL;
        root->r = NULL;
    }
    else if (val < root->key){
        insertHelp(x, root->l, h);
        if (h){
            switch (root->bal){
                case 1:
                    root->bal = 0;
                    h = false;
                    break
                case 0:
                    root->bal = -1;
                    break;
                case:
                    if (root->l->bal == -1){
                        LLturn(root, true)
                    }else{
                        LRturn(root, true);
                    }
                    h = false;
                    break;
            }
        }
    }
    else{
        insertHelp(val, root->r, h);
        if (h){
            switch (root->bal){
                case -1:
                    root->bal = 0;
                    h = false;
                    break;
                case 0:
                    root->bal = 1;
                    break;
                case 1:
                    if (root->l->bal == -1){
                        RRturn(root, true);
                    }else{
                        RLturn(root, true);
                    }
                    h = false;
                    break;
            }
        }
    }
}

void insert(int val, Node* root){
    bool h;
    insertHelp(val, root, h);
}

void balance1(Node* root, bool h){
    int tempBal1, tempBal2;

    tempBal1 = root->bal;
    switch(tempBal1){
        case -1:
            root->bal = 0;
            break;
        case 0:
            root->bal = 1;
            h = false;
            break;
        case 1:
            tempBal2 = root->r->bal;
            if (tempBal2 >= 0){
                RRturn(root, false);
            }else{
                RLturn(root, false);
            }
            if (tempBal2 == 0){
                h = false;
            }
            break;
    }
}

void balance2(Node* root, bool h){
    int tempBal1, tempBal2;

    tempBal1 = root->bal;
    switch(tempBal1){
        case 1:
            root->bal = 0;
            break;
        case 0:
            root->bal = -1;
            h = false;
            break;
        case -1:
            tempBal2 = root->l->bal;
            if (tempBal2 <= 0){
                LLturn(root, false);
            }else{
                LRturn(root, false);
            }
            if (tempBal2 == 0){
                h = false;
            }
            break;
    }
}

#endif AVL_TREE_H
