#ifndef __FISHINTERFACE_H__
#define __FISHINTERFACE_H__




struct FishInterface
{
	virtual const unsigned char& getLowestDepth () const =0;
};

#endif /* __FISHINTERFACE_H__ */
