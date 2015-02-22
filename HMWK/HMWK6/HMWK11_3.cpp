#include "HMWK11_3.h"

using namespace main_savitch_11;

template <class Item>
set<Item>::set() {
    data_count = 0;
    child_count = 0;
}

temmplate <class Item>
set<Item>set(const set& source) {
    *this = source;
}

template <class Item>
std::size_t set<Item>::count(const Item& target) const{
    int num = 0;
     for (int i=0; i<data.length && data[i] < target; i++);
         if (i < data.length && data[i] == target) //we found it
            num++;
     return num; 
}

template <class Item>
void set<Item>::loose_insert(const Item& entry) {
    for(int i = 0; i < data_count && data[i] < entry; i++) {
        //already present
        if(i < data.length && data[i] == entry)
            return;
        if(child_count == 0) {
            //add a new node
            for(int x = data.length-1; x > i; x--) {
                data[x] data[x-1]; //need room so shift over
            }
            data[i] = entry;
            data_count++;
        }
        else {
            //need a subset
            subset[i].loose_insert(entry);
            if(subset[i].data_count>MAXIMUM)
                fix_excess(i);
        }
    }
}

template <class Item>
void set<Item>::fix_excess(std::size_t i) {
    //move middle to root
    for(int ct = data_count; ct > i; ct--)
        data[ct] = data[ct-1];
    data[i]=subset[i].data[MINIMUM];
    data_count++;
    //split child into subtrees
    set lc = new set();
    set rc = new set();
    lc.data_count = MINIMUM;
    rc.data_count =MINIMUM;
    
    //copy data
    for(int ct = 0; ct < MINIMUM; ct++) {
        lc.data[ct] = subset[i].data[ct];
        rc.data[ct] subset[i].data[ct+MINIMUM+1];
    }
    
    //copy subsets of child
    int subChCt = (subset[i].child_count)/2;
    for(int c= = 0; ct<subChCt; ct++) {
        lc.subset[ct] = subset[i].subset[ct];
        rc.subset[ct] = subset[i].subset[ct+subChCt];
    }
    if(subChCt > 0) {
        lc.child_count = MINIMUM+1;
        rc.child_count = MINIMUM+1;
    }
    
    // make room in root's subset array for new children:
     subset[childCount] = new set();
     for (int ct = childCount; ct > i; ct--)
         subset[ct] = subset[ct-1];
         childCount++;
         // add new subsets to root's subset array:
         subset[i] = lc;
         subset[i+1] = rc;
     }
}

template <class Item>
void insert(const Item& entry) {
    loose_insert(entry);
    if (data_count > MAXIMUM) {
         // get ready to split root node
         set child = new set();
         // transfer data to new child:
         for (int x=0; x<data_count; x++)
             child.data[x] = data[x];
         for (int y=0; y<child_count; y++)
           child.subset[y] = subset[y];
        // finish setting up child set:
         child.child_count = child_count;
         child.data_count = data_count;
        // reset current node as empty, with 1 child
         data_count = 0;
         child_count = 1;
        // make new child subset of current node
         subset[0] = child;
        // fix problem of empty root node
         fix_excess(0);
     }
}

template<class Item>
bool set<Item>::erase(const Item& target)
{
    
    if (!(loose_erase(target)))
        return false;
    if (data_count == 0 && child_count ==1)
    {  
        set *child = new set;
    
        for(std::size_t i = 0; i < data_count; i++)
        child->data[i] = data[i];
    
        for(std::size_t i = 0; i < child_count; i++)
        child->subset[i] = subset[i];
    
        child->child_count = child_count;
        child->data_count = data_count;
    }
    return true;
}

template <class Item>
boolean set<Item>::loose_erase(const Item& target) {
    int fIndex = 0;
    for(; data[fIndex] < target && fIndex < MAXIMUM; fIndex++){}
    if(fIndex == MAXIMUM && data[fIndex]<=)
        fIndex = data_count;
    if()
}