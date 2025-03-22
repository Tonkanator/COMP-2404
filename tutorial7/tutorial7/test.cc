#include <istream>
#include <string>
#include <X11/Xlib.h>
#include "AbsolutePanel.h"
#include "FlowPanel.h"
#include "Tester.h"

#define ARR 5

using namespace std;

Tester tester;


// Test class for testing the draw method of the Panel classes
class TestComponent: public Component{
    public:
        TestComponent(int x, int y, int width, int height, const string& id): Component(x, y, width, height, id){};
        TestComponent(const Rectangle& rect, const string& id): Component(rect, id){};
        void draw(Display *display, Window win, GC gc, const Rectangle& box){
            cout<<"Drawing TestComponent: "<<id<<endl;
        }

        void print() const{
            cout<<"TestComponent: "<<id<<endl;
        }
};

int testAbsoluteDraw(Display* display, Window win, GC gc);
int testFlowDraw(Display* display, Window win, GC gc);

// int completeRepairTest();

int main(){

    int choice = 0;
    cout << "Which test would you like to run?"<< endl;
    cout << "  (0) Test draw in AbsolutePanel." << endl;
    cout << "  (1) Test draw in TestComponent" <<endl;
    cin >> choice;
    int ret = 0;
    switch(choice){
      case 0: ret = testAbsoluteDraw(NULL, 0, 0); break;
      case 1: ret = testFlowDraw(NULL, 0, 0); break;
    //   case 2: ret = completeRepairTest(); break;
    }

    return ret;
  
}

int testAbsoluteDraw(Display* display, Window win, GC gc){

    vector<string> ids = {"TestComponent 1", "TestComponent 2", "TestComponent 3", "TestComponent 4", "TestComponent 5", "TestComponent 6"};
    AbsolutePanel panel(0, 0, 500, 500, "AbsolutePanel");
    TestComponent* panel1  = new TestComponent(10, 10, 80, 50, "TestComponent 1");
    TestComponent* panel2  = new TestComponent(10, 50, 80, 50, "TestComponent 2");
    TestComponent* panel3  = new TestComponent(10, 60, 80, 50, "TestComponent 3");
    TestComponent* panel4  = new TestComponent(90, 60, 80, 50, "TestComponent 4");
    TestComponent* panel5  = new TestComponent(100, 60, 80, 50, "TestComponent 5");
    TestComponent* panel6  = new TestComponent(100, 180, 450, 50, "TestComponent 6");

    panel.add(panel1);
    panel.add(panel2);
    panel.add(panel3);
    panel.add(panel4);
    panel.add(panel5);
    panel.add(panel6);
    

    tester.initCapture();
    panel.draw(display, win, gc, Rectangle(0, 0, 500, 500));
    tester.endCapture();

    int error = 0;
    tester.findInOrder({0,2,3}, ids, error);

    if (error == 0){
        cout<<"Correct Components found"<<endl;
    }else{
        cout<<"Not all Components found, test failed"<<endl;
        return 1;
    }

    error = 0;
    tester.confirmAbsent({1,4,5}, ids, error);
    if (error == 0){
        cout<<"Incorrect Components not found"<<endl;
    }else{  
        cout<<"Incorrect Components found, test failed"<<endl;
        return 1;
    }

    cout<<"Removing TestComponent 1"<<endl;
    panel.remove("TestComponent 1");

    tester.initCapture();
    panel.draw(display, win, gc, Rectangle(0, 0, 500, 500));
    tester.endCapture();

    error = 0;
    tester.findInOrder({1,3}, ids, error);

    if (error == 0){
        cout<<"Correct Components found"<<endl;
    }else{
        cout<<"Not all Components found, test failed"<<endl;
        return 1;
    }

    error = 0;
    tester.confirmAbsent({0,2,5}, ids, error);
    if (error == 0){
        cout<<"Incorrect Components not found"<<endl;
    }else{  
        cout<<"Incorrect Components found, test failed"<<endl;
        return 1;
    }

    cout<<"AbsolutePanel test passed"<<endl;
    
    return 0;
}


int testFlowDraw(Display* display, Window win, GC gc){
    FlowPanel *panel1 = new FlowPanel(0, 0, 600, 300, "FlowPanel 1");
    // FlowPanel *panel2 = new FlowPanel(0, 300, 600, 300, "FlowPanel 2");
    // FlowPanel *panel3 = new FlowPanel(0, 0, 100, 50, "FlowPanel 3");

    TestComponent* textArea1 = new TestComponent({10, 10, 80, 50}, "TestComponent 1");
    TestComponent* textArea2 = new TestComponent({10, 70, 280, 150}, "TestComponent 2");
    TestComponent* button3 = new TestComponent({10, 130, 280, 70}, "TestComponent 3");
    TestComponent* textArea4 = new TestComponent({80, 210, 180, 90}, "TestComponent 4");
    TestComponent* textArea5 = new TestComponent({80, 210, 180, 90}, "TestComponent 5");


    panel1->add(textArea1);
    panel1->add(textArea2);
    panel1->add(button3);
    panel1->add(textArea4);

    // panel2->add(new TextArea(*textArea1 ));
    // panel2->add(new TextArea(*textArea2 ));
    panel1->add(textArea5);
    
    tester.initCapture();
    panel1->draw(display, win, gc, Rectangle(0, 0, 600, 300));
    tester.endCapture();

    int error = 0;
    vector<string> ids = {"TestComponent 1", "TestComponent 2", "TestComponent 3", "TestComponent 4", "TestComponent 5"};
    tester.findInOrder({0,1,2,3}, ids, error);

    if (error == 0){
        cout<<"Correct Components found"<<endl;
    }else{
        cout<<"Not all Components found, test failed"<<endl;
        return 1;
    }

    error = 0;
    tester.confirmAbsent({4}, ids, error);
    if (error == 0){
        cout<<"Incorrect Components not found"<<endl;
    }else{
        cout<<"Incorrect Components found, test failed"<<endl;
        return 1;
    }

    cout<<"Removing TestComponent 1"<<endl;
    panel1->remove("TestComponent 1");

    tester.initCapture();
    panel1->draw(display, win, gc, Rectangle(0, 0, 600, 300));
    tester.endCapture();

    tester.findInOrder({1,2,3,4}, ids, error);

    if (error == 0){
        cout<<"Correct Components found"<<endl;
    }else{
        cout<<"Not all Components found, test failed"<<endl;
        return 1;
    }

    error = 0;
    tester.confirmAbsent({0}, ids, error);
    if (error == 0){
        cout<<"Incorrect Components not found"<<endl;
    }else{
        cout<<"Incorrect Components found, test failed"<<endl;
        return 1;
    }

    cout<<"FlowPanel test passed"<<endl;
    
    return 0;

}

int repairTest(){
    // Repair* repairs[ARR];
    // vector<int> repairCodes = {1,7,6,3,4};
    // vector<double> costs = {100,200,300,400,500};
    // for (int i = 0; i < ARR; i++){
    //     repairs[i] = new Repair(repairCodes[i], costs[i]);
    // }

    // tester.initCapture();
    // for (int i = 0; i < ARR; i++){
    //     repairs[i]->print();
    // }
    // tester.endCapture();

    // int error = 0;
    // int mark = 0;
    // tester.find(repairCodes, Garage::REPAIRS, error);
    // if (error == 0){
    //     cout<<"Repairs found"<<endl;
    // }else{
    //     cout<<"Repairs not found, test failed"<<endl;
    //     return 1;
    // }

    

    return 0;
}





