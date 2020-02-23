#ifndef RTLSDRSOURCE_H
#define RTLSDRSOURCE_H

#include <rtl-sdr.h>
#include <iostream>
#include <vector>
#include <complex>
#include <exception>

/** Exception for bad rtl-sdr API calls. rtl-sdr functions often return non-zero for errors */
class badRtlSdrApiCall : public std::exception
{
public:
	badRtlSdrApiCall(void):
		std::exception()
		{

		}
};

/** RTL-SDR Source class */
class rtlSdrSource
{
public:
	
	/** Empty Constructor
	*
	*
	*
	*/
	//rtlSdrSource();

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
	/** Get the gain mode of the rtl-sdr (0 automatic, 1 manual*/
	int getTunerGainMode();
	/** Get the gain of the rtl-sdr*/
	int getTunerGain();
	/** Get the freuqnecy correction of the rtl-sdr*/
	int getFrequencyCorrection();
	/** Get the tuner bandwidth of the rtl-sdr*/
	double getTunerBandwidth();
	/** Get the status of automatic gain control mode*/
	int getAutomaticGainControlMode();
	/** Get the status of direct sampling mode*/
	int getDirectSampling();

	/** Setters */
	/** Set the device ID of the rtl-sdr */
	void setDeviceId(int device_id);
	/** Set the center frequency of the rtl-sdr*/
	void setCenterFrequency(double center_frequency);
	/** Set the sample rate of the rtl-sdr*/
	void setSampleRate(double sample_rate);
	/** Set the gain mode  of the rtl-sdr (0 automatic, 1 manual*/
	void setTunerGainMode(int tuner_gain_mode);
	/** Set the gain of the rtl-sdr*/
	void setTunerGain(int tuner_gain);
	/** Set the freuqnecy correction of the rtl-sdr*/
	void setFrequencyCorrection(int frequency_correction);
	/** Set the tuner bandwidth of the rtl-sdr*/
	void setTunerBandwidth(double tuner_bandwidth);
	/** Set the automatic gain control mode*/
	void setAutomaticGainControlMode(int automatic_gain_control_mode);
	/** Set direct sampling mode*/
	void setDirectSampling(int direct_sampling_mode);

	/** This function returns a vector of IQ data to be processed */
	std::vector<std::complex<double>> readIqSamples(int iq_block_length);

private:
	/** Holds the device ID of the rtl-sdr. */
	int				device_id_;
	/** Holds the center frequency of the rtl-sdr. */
	double			center_frequency_;
	/** Holds the sample rate of the rtl-sdr. */
	double			sample_rate_;
	/** Holds the rtl-sdr tuner gain mode (0 automatic 1 manual) */
	int				tuner_gain_mode_;
	/** Holds the rtl-sdr tuner gain */
	int				tuner_gain_;
	/** Holds the rtl-sdr frequency correction */
	int				frequency_correction_;
	/** Holder the rtl-sdr tuner bandwidth */
	double			tuner_bandwidth_;
	/** Holder automatic gain control mode */
	int			automatic_gain_control_mode_;
	/** Holder of direct sampling mode */
	int			direct_sampling_mode_;
	/** Holds the rtl-sdr device object. */
	rtlsdr_dev_t 	*device_;

};

#endif