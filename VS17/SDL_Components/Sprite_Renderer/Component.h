#ifndef __COMPONENT_H__
#define __COMPONENT_H__

class Component {

private:


public:
	Component();
	~Component();

	virtual void Start() {}
	virtual void Update() {}

};

#endif // !__COMPONENT_H__


