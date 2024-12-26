#pragma once
#include <string>
#include <vector>
using namespace std;

template <typename T_REG>
class IOFile
{
public:
    IOFile(const string& sPathFile)
    {
        m_sPathFile = sPathFile.c_str();
    }

public:
    bool Grava(unsigned long& ulPosicao, const T_REG& regValores)
    {
        CFile file;
        if (!file.Open(m_sPathFile, CFile::modeWrite | CFile::typeBinary | CFile::modeNoTruncate | CFile::modeCreate))
            return false;

        if (ulPosicao)
        {
            if (!ValidaOffset(ulPosicao, file))
                return false;

            file.Seek(GetOffset(ulPosicao), CFile::begin);
        }
        else
        {
            file.SeekToEnd();
            ulPosicao = GetQtdRegistros(file) + 1;
        }

        file.Write(&regValores, sizeof(T_REG));
        file.Close();

        return true;
    }

    bool GravaLista(unsigned long& ulPosicao, const vector<T_REG>& aregValores)
    {
        for (size_t idx = 0; idx < aregValores.size(); ++idx)
        {
            unsigned long ulPosGravacao = 0;
            if (!Grava(ulPosGravacao, aregValores[idx]))
                return false;

            if (!idx)
                ulPosicao = ulPosGravacao;
        }

        return true;
    }

    bool Le(unsigned long ulPosicao, T_REG& regValores)
    {
        if (!ulPosicao)
            return false;

        CFile file;
        if (!file.Open(m_sPathFile, CFile::modeRead | CFile::typeBinary | CFile::modeNoTruncate))
            return false;

        if (!ValidaOffset(ulPosicao, file))
            return false;

        file.Seek(GetOffset(ulPosicao), CFile::begin);

        file.Read(&regValores, sizeof(T_REG));
        file.Close();

        return true;
    }

    bool LeLista(unsigned long ulPosicao, unsigned long ulQtd, vector<T_REG>& aregValores)
    {
        aregValores.resize(ulQtd);

        for (size_t idx = 0; idx < aregValores.size(); ++idx)
        {
            if (!Le(ulPosicao + idx, aregValores[idx]))
                return false;
        }

        return true;
    }

    bool LeTudo(vector<T_REG>& aregValores)
    {
        aregValores.clear();

        CFile file;
        if (!file.Open(m_sPathFile, CFile::modeRead | CFile::typeBinary | CFile::modeNoTruncate))
            return false;

        unsigned long ulQtd = GetQtdRegistros(file);
        aregValores.resize(ulQtd);

        file.SeekToBegin();

        for (unsigned long idx = 0; idx < ulQtd; ++idx)
        {
            file.Read(&aregValores[idx], sizeof(T_REG));
        }

        file.Close();

        return true;
    }

private:
    long long GetOffset(unsigned long ulPosicao)
    {
        return (ulPosicao - 1) * sizeof(T_REG);
    }

    unsigned long GetQtdRegistros(CFile& file)
    {
        return (unsigned long) file.GetLength() / sizeof(T_REG);
    }

    bool ValidaOffset(unsigned long ulPosicao, CFile& file)
    {
        return ulPosicao <= GetQtdRegistros(file);
    }

private:
    CString m_sPathFile;
};