#include "Item_simple.h"
#include "Item.h"
#pragma once

class Item_complexe : public Item
{
    private:
        Item_simple *pc;
    public:
        Item_complexe();
        Item_complexe(int n);
        ~Item_complexe();
};