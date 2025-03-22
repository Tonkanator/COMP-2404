#ifndef SEARCH_H
#define SEARCH_H

#include "defs.h"
#include <iostream>
#include <string>

#include "Media.h"

class Search {
    public:
        virtual bool matches(const Media *) const = 0;
        virtual void print(std::ostream &ost) const = 0;
        friend std::ostream& operator<<(std::ostream& ost, const Search& search);
};

class O_Search: public virtual Search {
    protected:
        std::string owner;
    public:
        O_Search(const std::string& owner);
        bool matches(const Media* media) const override;
        void print(std::ostream &ost) const override;
};

class C_Search: public virtual Search {
    protected:
        std::string category;
    public:
        C_Search(const std::string& category);
        bool matches(const Media *media) const override;
        void print(std::ostream &ost) const override;
};

class OorC_Search: public O_Search, public C_Search {
    public:
        OorC_Search(const std::string& owner, const std::string& category);
        bool matches(const Media *media) const override;
        void print(std::ostream &ost) const override;
};

#endif