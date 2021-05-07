#include <iostream>

template<class CL1>
class Node{
    public: CL1 c_Field;
    public: Node* cp_Next;
    public: Node* cp_Prev;
    public: Node(CL1 c_Field){
        this->c_Field   = c_Field;
        cp_Next = nullptr;
        cp_Prev = nullptr;
    }
};

template<class CL1>
class Sp2LS{
    public: Node<CL1>* cp_Start;
    public: Node<CL1>* cp_Curr;
    private: int i_NumNd;

    public: Sp2LS(){
        cp_Start = cp_Curr = nullptr;
        i_NumNd = 0;
    }
    public:~Sp2LS(){
        for(Node<CL1>* op_TmpC= cp_Start;
            op_TmpC != nullptr;){
            Node<CL1>* op_TmpN= op_TmpC->cp_Next;
            delete op_TmpC;
            op_TmpC = op_TmpN;
        }
    }

    public: void fn_Trace(){
        std::cout<< "(nullptr->)start->";
        for(Node<CL1>* op_TmpC= cp_Start;
            op_TmpC != nullptr;
            op_TmpC = op_TmpC->cp_Next){

            std::cout<< op_TmpC->c_Field << "->";
        }
        std::cout<< "nullptr" << "\n";
    }

    public: void fn_AddNode(CL1 c_Field){
        Node<CL1>* op_Node = new Node<CL1>(c_Field);
        if(cp_Start == nullptr){
            op_Node->cp_Prev = nullptr;
            cp_Start = op_Node;
            cp_Curr = op_Node;
        }
        else{
            op_Node->cp_Prev = cp_Curr;
            cp_Curr->cp_Next = op_Node;
            cp_Curr = op_Node;
        }
        i_NumNd++;
    }

    public: bool fn_DelNode(int i_Ind = 0){
        bool b_IsSuc = true;
        if(i_Ind > (i_NumNd -1)){
            b_IsSuc = false;
        }
        else{
            Node<CL1>* op_TmpC = cp_Start;
            if(i_Ind< (i_NumNd / 2)){
                for(int i_Ct= 0; i_Ct< i_Ind + 1; i_Ct++){
                    if(i_Ct == 0){
                        continue;
                    }
                    op_TmpC = op_TmpC->cp_Next;
                }
            }
            else{
                op_TmpC = cp_Curr;
                for(int i_Ct= i_NumNd -1; i_Ct>= i_Ind; i_Ct--){
                    if(i_Ct == (i_NumNd -1)){
                        continue;
                    }
                    op_TmpC = op_TmpC->cp_Prev;
                }
            }

            if(i_Ind == 0){
                cp_Start = cp_Start->cp_Next;
                cp_Start->cp_Prev = nullptr;
                if(i_NumNd == 1){
                    cp_Curr = nullptr;
                }
            }
            else if(i_Ind == (i_NumNd -1) && i_Ind != 0){
                cp_Curr = op_TmpC->cp_Prev;
            }
            else{
                (op_TmpC->cp_Prev)->cp_Next = (op_TmpC->cp_Next);
                (op_TmpC->cp_Next)->cp_Prev = (op_TmpC->cp_Prev);
            }
            delete op_TmpC;
            i_NumNd--;
        }
        return b_IsSuc;
    }

    public: void fn_UpdNode(int i_Ind, CL1 c_Field){

    }

    public: void fn_InsNode(int i_Ind, CL1 c_Field){

    }
};
int main(){
    Sp2LS<int> o_LS;
    o_LS.fn_AddNode(3);
    o_LS.fn_AddNode(7);
    o_LS.fn_AddNode(6);
    o_LS.fn_AddNode(4);
    o_LS.fn_AddNode(2);
    o_LS.fn_AddNode(8);
    o_LS.fn_AddNode(1);

    o_LS.fn_Trace();

    o_LS.fn_DelNode(5);
    o_LS.fn_DelNode(1);
    o_LS.fn_DelNode(0);
    o_LS.fn_Trace();
    return 0;
}
