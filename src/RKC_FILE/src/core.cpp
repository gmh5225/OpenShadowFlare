#include <Windows.h>
#include <cstdint>

class RKC_FILE
{
public:
    HANDLE m_handle;
};

extern "C"
{
    void __thiscall RKC_FILE_constructor(RKC_FILE* file)
    {
        file->m_handle = 0;
    }

    void __thiscall RKC_FILE_deconstructor(RKC_FILE* file)
    {
        file->m_handle = 0;
    }

    int __thiscall Create(RKC_FILE* file, char* fileName, long desiredAccess)
    {
        bool result = false;
        switch (desiredAccess)
        {
            case 0:
                file->m_handle = CreateFileA(fileName, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
                result = file->m_handle != INVALID_HANDLE_VALUE;
                break;
            case 1:
                file->m_handle = CreateFileA(fileName, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
                result = file->m_handle != INVALID_HANDLE_VALUE;
                break;
            case 2:
                file->m_handle = CreateFileA(fileName, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
                result = file->m_handle != INVALID_HANDLE_VALUE;
                break;
            case 3:
                file->m_handle = CreateFileA(fileName, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
                result = file->m_handle != INVALID_HANDLE_VALUE;
                if (result)
                    SetFilePointer(file->m_handle, 0, 0, 2);
                break;
            default:
                break;
        }

        return result;
    }

    int __thiscall Close(RKC_FILE* file)
    {
        bool result = false;

        if (!file->m_handle || (result = CloseHandle(file->m_handle)))
        {
            file->m_handle = 0;
            return 1;
        }

        return result;
    }

    int __thiscall Write(RKC_FILE* file, void* buffer, long numBytesToWrite)
    {
        DWORD bytesWritten = 0;
        bool result = WriteFile(file->m_handle, buffer, numBytesToWrite, &bytesWritten, nullptr);
        if (bytesWritten != numBytesToWrite)
            return false;

        return result;
    }

    int __thiscall Read(RKC_FILE* file, void* buffer, long numBytesToRead)
    {
        DWORD bytesRead = 0;
        bool result = ReadFile(file->m_handle, buffer, numBytesToRead, &bytesRead, nullptr);
        if (bytesRead != numBytesToRead)
            return false;

        return result;
    }

    long __thiscall GetSize(RKC_FILE* file)
    {
        DWORD fileSizeHigh = 0;
        if (file->m_handle)
            return GetFileSize(file->m_handle, &fileSizeHigh);

        return -1;
    }

    int __thiscall Seek(RKC_FILE* file, long distanceToMove, long moveMethod)
    {
        if (moveMethod < 0 || moveMethod > 2)
            return false;

        return SetFilePointer(file->m_handle, distanceToMove, 0, moveMethod);
    }

    RKC_FILE& __thiscall equalsOperator(RKC_FILE* file, const RKC_FILE& lhs)
    {
        file->m_handle = lhs.m_handle;
        return *file;
    }

    HANDLE __thiscall GetHandle(RKC_FILE * file)
    {
        return file->m_handle;
    }
}
bool __stdcall DllMain(LPVOID, std::uint32_t call_reason, LPVOID)
{
    return true;
}