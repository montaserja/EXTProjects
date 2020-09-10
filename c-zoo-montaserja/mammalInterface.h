

#ifndef __MAMMALINTERFACE_H__
#define __MAMMALINTERFACE_H__




struct MammalInterface
{
	virtual const unsigned char& getPregnancyDuration() const =0;
	virtual const unsigned char& getNumberYoungBorn()const =0;
	
};

#endif /* __MAMMALINTERFACE_H__ */
