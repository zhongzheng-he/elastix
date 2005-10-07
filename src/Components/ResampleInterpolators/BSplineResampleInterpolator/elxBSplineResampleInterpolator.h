#ifndef __elxBSplineResampleInterpolator_h
#define __elxBSplineResampleInterpolator_h

#include "itkBSplineInterpolateImageFunction.h"
#include "elxIncludes.h"

namespace elastix
{
	using namespace itk;
	
	/**
	 * \class BSplineResampleInterpolator
	 * \brief A resample-interpolator based on B-splines.
	 *
	 * The parameters used in this class are:
	 * \parameter ResampleInterpolator: Select this resample interpolator as follows:\n
	 *		<tt>(ResampleInterpolator "FinalBSplineInterpolator")</tt>
	 *
	 * \ingroup ResampleInterpolators
	 */

	template < class TElastix	>
		class BSplineResampleInterpolator :
	public
		BSplineInterpolateImageFunction<
		ITK_TYPENAME ResampleInterpolatorBase<TElastix>::InputImageType,
		ITK_TYPENAME ResampleInterpolatorBase<TElastix>::CoordRepType,
		double >, //CoefficientType
	public ResampleInterpolatorBase<TElastix>
	{
	public:

		/** Standard ITK-stuff. */
		typedef BSplineResampleInterpolator						Self;
		typedef BSplineInterpolateImageFunction<
			typename ResampleInterpolatorBase<TElastix>::InputImageType,
			typename ResampleInterpolatorBase<TElastix>::CoordRepType,
			double >																		Superclass1;
		typedef ResampleInterpolatorBase<TElastix>		Superclass2;
		typedef SmartPointer<Self>										Pointer;
		typedef SmartPointer<const Self>						  ConstPointer;
		
		/** Method for creation through the object factory. */
		itkNewMacro( Self );
		
		/** Run-time type information (and related methods). */
		itkTypeMacro( BSplineResampleInterpolator, BSplineInterpolateImageFunction );
		
		/** Name of this class.
		 * Use this name in the parameter file to select this specific resample interpolator. \n
		 * example: <tt>(ResampleInterpolator "FinalBSplineInterpolator")</tt>\n
		 */
		elxClassNameMacro( "FinalBSplineInterpolator" );

		/** Dimension of the image. */
		itkStaticConstMacro( ImageDimension, unsigned int,Superclass1::ImageDimension );
		
		/** Typedef's inherited from the superclass. */
		typedef typename Superclass1::OutputType	 							OutputType;
		typedef typename Superclass1::InputImageType						InputImageType;
		typedef typename Superclass1::IndexType									IndexType;
		typedef typename Superclass1::ContinuousIndexType				ContinuousIndexType;
		typedef typename Superclass1::PointType									PointType;
		typedef typename Superclass1::Iterator									Iterator;
		typedef typename Superclass1::CoefficientDataType				CoefficientDataType;
		typedef typename Superclass1::CoefficientImageType			CoefficientImageType;
		typedef typename Superclass1::CoefficientFilter					CoefficientFilter;
		typedef typename Superclass1::CoefficientFilterPointer	CoefficientFilterPointer;
		typedef typename Superclass1::CovariantVectorType				CovariantVectorType;
		
		/** Typedef's from ResampleInterpolatorBase. */
		typedef typename Superclass2::ElastixType								ElastixType;
		typedef typename Superclass2::ElastixPointer						ElastixPointer;
		typedef typename Superclass2::ConfigurationType					ConfigurationType;
		typedef typename Superclass2::ConfigurationPointer			ConfigurationPointer;
		typedef typename Superclass2::RegistrationType					RegistrationType;
		typedef typename Superclass2::RegistrationPointer				RegistrationPointer;
		typedef typename Superclass2::ITKBaseType								ITKBaseType;
		
		/** Execute stuff before the actual registration:
		 * \li Set the spline order.
		 */
		virtual void BeforeRegistration(void);

		/** Function to read transform-parameters from a file. */
		virtual void ReadFromFile(void);
		/** Function to write transform-parameters to a file. */
		virtual void WriteToFile(void);

	protected:

		/** The constructor. */
		BSplineResampleInterpolator() {}
		/** The destructor. */
		virtual ~BSplineResampleInterpolator() {}
						
	private:

		/** The private constructor. */
		BSplineResampleInterpolator( const Self& );	// purposely not implemented
		/** The private copy constructor. */
		void operator=( const Self& );							// purposely not implemented
			
	}; // end class BSplineResampleInterpolator
	
	
} // end namespace elastix

#ifndef ITK_MANUAL_INSTANTIATION
#include "elxBSplineResampleInterpolator.hxx"
#endif

#endif // end __elxBSplineResampleInterpolator_h

