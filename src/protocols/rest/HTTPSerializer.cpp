#include "protocols/rest/HTTPSerializer.h"

namespace eProsima
{

	namespace httpser
	{

		HTTPSerializer::HTTPSerializer(FastBuffer &buffer) : buffer_(buffer), m_lastDataSize_(0), m_currentPosition_(buffer.begin()), m_alignPosition_(buffer.begin()), m_lastPosition_(buffer.end())
		{

		}

		HTTPSerializer::~HTTPSerializer()
		{

		}

		void HTTPSerializer::state(HTTPSerializer &serializer)
		{
			 m_currentPosition_bck = serializer.m_currentPosition_;
			 m_alignPosition_bck = serializer.m_alignPosition_;
			 m_lastDataSize_bck = serializer.m_lastDataSize_;
		}

		void HTTPSerializer::setState()
		{
			m_currentPosition_ = m_currentPosition_bck;
			m_alignPosition_ = m_alignPosition_bck;
			m_lastDataSize_ = m_lastDataSize_bck;
		}

		bool HTTPSerializer::resize(size_t minSizeInc)
		{
			if(buffer_.resize(minSizeInc)){
				m_currentPosition_ = buffer_.begin();
				m_alignPosition_ = buffer_.begin();
				m_lastPosition_ = buffer_.end();
				return true;
			}
			return false;
		}

		void HTTPSerializer::reset()
		{
			m_currentPosition_ = buffer_.begin();
			m_alignPosition_ = buffer_.begin();
			m_lastDataSize_ = 0;
		}

		HTTPSerializer& HTTPSerializer::serialize(uint32_t &integer)
		{
			size_t align = alignment(sizeof(integer));
			size_t sizeAligned = sizeof(integer) + align;

			if(((m_lastPosition_ - m_currentPosition_) >= sizeAligned) || resize(sizeAligned))
			{
				// Save last datasize.
				m_lastDataSize_ = sizeof(integer);
    
				// Align.
				makeAlign(align);

				m_currentPosition_ << integer;
				m_currentPosition_ += sizeof(integer);
				
				return *this;
			}

			//throw NotEnoughMemoryException(NotEnoughMemoryException::NOT_ENOUGH_MEMORY_MESSAGE_DEFAULT);
		}

		HTTPSerializer& HTTPSerializer::deserialize(uint32_t &integer)
		{
			size_t align = alignment(sizeof(integer));
			size_t sizeAligned = sizeof(integer) + align;

			if((m_lastPosition_ - m_currentPosition_) >= sizeAligned)
			{
				// Save last datasize.
				m_lastDataSize_ = sizeof(integer);

				// Align
				makeAlign(align);

				m_currentPosition_ >> integer;
				m_currentPosition_ += sizeof(integer);
				return *this;
			}

			//throw NotEnoughMemoryException(NotEnoughMemoryException::NOT_ENOUGH_MEMORY_MESSAGE_DEFAULT);
		}

		HTTPSerializer& HTTPSerializer::serialize(std::string &string_t)
		{
			uint32_t length = (uint32_t)string_t.length();
		    state(*this);
	
		    serialize(length);
			
			if(length > 0)
			{
				if(((m_lastPosition_ - m_currentPosition_) >= length) || resize(length))
				{
					// Save last datasize.
					m_lastDataSize_ = sizeof(uint8_t);
					m_currentPosition_.memcopy(string_t.c_str(), length);
					m_currentPosition_ += length;
				}
				else
				{
					setState();
					//throw NotEnoughMemoryException(NotEnoughMemoryException::NOT_ENOUGH_MEMORY_MESSAGE_DEFAULT);
				}
			}

			return *this;
		}

		HTTPSerializer& HTTPSerializer::deserialize(std::string &string_t)
		{
			uint32_t length = 0;
			state(*this);

			deserialize(length);

			if(length == 0)
			{
				string_t = "";
				return *this;
			}
			else if((m_lastPosition_ - m_currentPosition_) >= length)
			{
				// Save last datasize.
				m_lastDataSize_ = sizeof(uint8_t);

				string_t = std::string(&m_currentPosition_, length - ((&m_currentPosition_)[length-1] == '\0' ? 1 : 0));
				m_currentPosition_ += length;
				return *this;
			}

			setState();
			//throw NotEnoughMemoryException(NotEnoughMemoryException::NOT_ENOUGH_MEMORY_MESSAGE_DEFAULT);
		}

		HTTPSerializer& HTTPSerializer::serialize(HTTPMethod &method)
		{
			return HTTPSerializer::serialize(method.get_data());
		}

		HTTPSerializer& HTTPSerializer::deserialize(HTTPMethod &method)
		{
			return HTTPSerializer::deserialize(method.get_data());
		}

		HTTPSerializer& HTTPSerializer::serialize(HTTPUri &uri)
		{
			return HTTPSerializer::serialize(uri.get_data());
		}

		HTTPSerializer& HTTPSerializer::deserialize(HTTPUri &uri)
		{
			return HTTPSerializer::deserialize(uri.get_data());
		}

		HTTPSerializer& HTTPSerializer::serialize(HTTPVersion &version)
		{
			return HTTPSerializer::serialize(version.get_data());
		}

		HTTPSerializer& HTTPSerializer::deserialize(HTTPVersion &version)
		{
			return HTTPSerializer::deserialize(version.get_data());
		}

		HTTPSerializer& HTTPSerializer::serialize(HTTPData &data)
		{
			return HTTPSerializer::serialize(data.get_data());
		}

		HTTPSerializer& HTTPSerializer::deserialize(HTTPData &data)
		{
			return HTTPSerializer::deserialize(data.get_data());
		}

		HTTPSerializer& HTTPSerializer::serialize(HTTPResponseCode &responseCode)
		{
			return HTTPSerializer::serialize(responseCode.get_data());
		}

		HTTPSerializer& HTTPSerializer::deserialize(HTTPResponseCode &responseCode)
		{
			return HTTPSerializer::deserialize(responseCode.get_data());
		}

		HTTPSerializer& HTTPSerializer::serialize(HTTPParam &param)
		{
			return HTTPSerializer::serialize(param.get_data());
		}

		HTTPSerializer& HTTPSerializer::deserialize(HTTPParam &param)
		{
			return HTTPSerializer::deserialize(param.get_data());
		}

		HTTPSerializer& HTTPSerializer::serialize(HTTPParameters &params, size_t numElements)
		{
			for(int i=0; i < numElements; ++i){
				HTTPSerializer::serialize(params.get_params().at(i));
			}
			return *this;
		}

		HTTPSerializer& HTTPSerializer::deserialize(HTTPParameters &params, size_t numElements)
		{
			HTTPParam param;
			std::string parametersData = "";
			for(int i=0; i < numElements; ++i){
				HTTPSerializer::deserialize(param);
				params.addParam(param);
			}
			return *this;
		}

	} //namespace httpser

} //namespace eProsima