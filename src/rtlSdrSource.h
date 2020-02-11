#ifndef RTLSDRSOURCE_H
#define RTLSDRSOURCE_H

#include <rtl-sdr.h>

class rtlSdrSource
{
public:
	
	/** Empty Constructor
	*
	*
	*
	*/
	rtlSdrSource();
	/** Constructor
	*
	* @param device_id
	* @param frequency
	* @param sample_rate
	*/
	rtlSdrSource(int device_id, double center_frequency, double sample_rate);

	/** Destructor */
	~rtlSdrSource();

	/** Getters */
	/** Get the device ID of the rtl-sdr */
	int getDeviceId();
	/** Get the center frequency of the rtl-sdr*/
	double getCenterFrequency();
	/** Get the sample rate of the rtl-sdr*/
	double getSampleRate();
	/** Get the device pointer of the rtl-sdr*/
	//*rtlsdr_dev_t getDeviceObject();

	/** Setters */
	/** Set the device ID of the rtl-sdr */
	void setDeviceId(int device_id);
	/** Set the center frequency of the rtl-sdr*/
	void setCenterFrequency(double center_frequency);
	/** Set the sample rate of the rtl-sdr*/
	void setSampleRate(double sample_rate);

private:
	/** Holds the device ID of the rtl-sdr. */
	int		device_id_;
	/** Holds the center frequency of the rtl-sdr. */
	double	center_frequency_;
	/** Holds the sample rate of the rtl-sdr. */
	double	sample_rate_;
	/** Holds the rtl-sdr device object. */
	rtlsdr_dev_t *device_;
};

#endif