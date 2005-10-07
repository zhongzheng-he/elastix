#ifndef __elxTranslationTransform_H_
#define __elxTranslationTransform_H_

#include "itkTranslationTransform.h"
#include "elxIncludes.h"

namespace elastix
{
	using namespace itk;
	
	/**
	 * \class TranslationTransformElastix
	 * \brief A transform based on the itk::TranslationTransform.
	 *
	 * This transform is a translation transformation.
	 *
	 * The parameters used in this class are:
	 * \parameter Transform: Select this transform as follows:\n
	 *		<tt>(Transform "TranslationTransform")</tt>
	 *
	 * \ingroup Transforms
	 */

	template < class TElastix >
		class TranslationTransformElastix:
			public TransformGrouper<
				TranslationTransform<
					ITK_TYPENAME elx::TransformBase<TElastix>::CoordRepType,
					elx::TransformBase<TElastix>::FixedImageDimension >		> ,
			public elx::TransformBase<TElastix>
	{
	public:
		
		/** Standard ITK-stuff. */
		typedef TranslationTransformElastix											Self;
		typedef TranslationTransform<
			typename elx::TransformBase<TElastix>::CoordRepType,
			elx::TransformBase<TElastix>::FixedImageDimension >		Superclass1;
		typedef elx::TransformBase<TElastix>										Superclass2;
		typedef SmartPointer<Self>															Pointer;
		typedef SmartPointer<const Self>												ConstPointer;
		
		/** Method for creation through the object factory. */
		itkNewMacro( Self );
		
		/** Run-time type information (and related methods). */
		itkTypeMacro( TranslationTransformElastix, TranslationTransform );

		/** Name of this class.
		 * Use this name in the parameter file to select this specific transform. \n
		 * example: <tt>(Transform "TranslationTransform")</tt>\n
		 */
		elxClassNameMacro( "TranslationTransform" );

		/** Dimension of the domain space. */
		itkStaticConstMacro( SpaceDimension, unsigned int, Superclass2::FixedImageDimension );
		
		/** Typedefs inherited from the superclass. */
		typedef typename Superclass1::ScalarType 								ScalarType;
		typedef typename Superclass1::ParametersType 						ParametersType;
		typedef typename Superclass1::JacobianType 							JacobianType;
		typedef typename Superclass1::InputVectorType						InputVectorType;
		typedef typename Superclass1::OutputVectorType 					OutputVectorType;
		typedef typename Superclass1::InputCovariantVectorType 	InputCovariantVectorType;
		typedef typename Superclass1::OutputCovariantVectorType	OutputCovariantVectorType;
		typedef typename Superclass1::InputVnlVectorType 				InputVnlVectorType;
		typedef typename Superclass1::OutputVnlVectorType				OutputVnlVectorType;
		typedef typename Superclass1::InputPointType 						InputPointType;
		typedef typename Superclass1::OutputPointType						OutputPointType;
		
		/** Typedef's from the TransformBase class. */
		typedef typename Superclass2::ElastixType								ElastixType;
		typedef typename Superclass2::ElastixPointer						ElastixPointer;
		typedef typename Superclass2::ConfigurationType					ConfigurationType;
		typedef typename Superclass2::ConfigurationPointer			ConfigurationPointer;
		typedef typename Superclass2::RegistrationType					RegistrationType;
		typedef typename Superclass2::RegistrationPointer				RegistrationPointer;
		typedef typename Superclass2::CoordRepType							CoordRepType;
		typedef typename Superclass2::FixedImageType						FixedImageType;
		typedef typename Superclass2::MovingImageType						MovingImageType;
		typedef typename Superclass2::ITKBaseType								ITKBaseType;
		
		/** Execute stuff before the actual registration:
		 * \li Create initial registration parameters.
		 */
		virtual void BeforeRegistration(void);

	protected:

		/** The constructor. */
		TranslationTransformElastix();
		/** The destructor. */
		virtual ~TranslationTransformElastix() {};
		
	private:

		/** The private constructor. */
		TranslationTransformElastix( const Self& );	// purposely not implemented
		/** The private copy constructor. */
		void operator=( const Self& );							// purposely not implemented
		
	}; // end class TranslationTransformElastix
	
	
} // end namespace elastix

#ifndef ITK_MANUAL_INSTANTIATION
#include "elxTranslationTransform.hxx"
#endif

#endif // end #ifndef __elxTranslationTransform_H_
