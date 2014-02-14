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

bool BaseView::HandleKeyEvent(KeyEvent* keyEvent) {
    if (this->HandleKeyEventSelf(keyEvent)) {
        return true;
    }

    for (vector<BaseView*>::iterator iter = this->children.begin(); iter != this->children.end(); iter++) {
        if ((*iter)->HandleKeyEvent(keyEvent)) {
            return true;
        }
    }

    return false;
}
