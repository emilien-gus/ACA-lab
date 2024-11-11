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

#endif AVL_TREE_H
