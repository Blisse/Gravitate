#include "BaseView.h"

using namespace Gravity;
using namespace std;

BaseView::BaseView() {
    isVisible = true;
}

BaseView::~BaseView() {

}

void BaseView::Paint() {
    this->PaintSelf();

    for (vector<BaseView*>::iterator iter = this->children.begin(); iter != this->children.end(); iter++) {
        (*iter)->Paint();
    }
}

void BaseView::AddChild(BaseView* view) {
    this->children.push_back(view);
}
