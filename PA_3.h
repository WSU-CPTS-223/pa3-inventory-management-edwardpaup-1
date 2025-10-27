#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "LinkedList.h"
using namespace std;

class Data{
private: 
string id;
string name;
string brand;
string Asin;
List<string> category;
string upcEanCode;
string listPrice;
string sellPrice;
string quantity;
string modelNum;
string productInfo;
string productSpec;
string techDetails;
string shipWeight;
string prodDimensions;
string image;
string variants;
string sku;
string url;
string stock;
string prodDetails;
string dimension;
string color;
string ingredients;
string directions;
string isAmazonSeller;
string sizeQuantVar;
string productDescription;
public:

    Data() : id(""), name(""), brand(""), Asin(""), category(), upcEanCode(""), listPrice(""), sellPrice(""), quantity(""),
            modelNum(""), productInfo(""), productSpec(""), techDetails(""), shipWeight(""), prodDimensions(""), image(""), variants(""), 
            sku(""), url(""), stock(""), prodDetails(""), dimension(""), color(""), ingredients(""), directions(""), isAmazonSeller(""),
            sizeQuantVar(""), productDescription("") {};

    List<string> getCategory() {return category;}
    string getId() {return id;}

    void setId(string newId) {id = newId;}
    void setName(string newName) {name = newName;}
    void setBrand(string newBrand) {brand = newBrand;}
    void setAsin(string newAsin) {Asin = newAsin;}
    void setUpcEanCode(string newUpcEanCode) {upcEanCode = newUpcEanCode;}
    void setListPrice(string newListPrice) {listPrice = newListPrice;}
    void setSellPrice(string newSellPrice) {sellPrice = newSellPrice;}
    void setQuantity(string newQuantity) {quantity = newQuantity;}
    void setModelNum(string newModelNum) {modelNum = newModelNum;}
    void setProductInfo(string newProductInfo) {productInfo = newProductInfo;}
    void setProductSpec(string newProductSpec) {productSpec = newProductSpec;}
    void setTechDetails(string newTechDetails) {techDetails = newTechDetails;}
    void setShipWeight(string newShipWeight) {shipWeight = newShipWeight;}
    void setProdDimensions(string newProdDimensions) {prodDimensions = newProdDimensions;}
    void setImage(string newImage) {image = newImage;}
    void setVariants(string newVariants) {variants = newVariants;}
    void setSku(string newSku) {sku = newSku;}
    void setUrl(string newUrl) {url = newUrl;}
    void setStock(string newStock) {stock = newStock;}
    void setProdDetails(string newProdDetails) {prodDetails = newProdDetails;}
    void setDimension(string newDimension) {dimension = newDimension;}
    void setColor(string newColor) {color = newColor;}
    void setIngredients(string newIngredients) {ingredients = newIngredients;}
    void setDirections(string newDirections) {directions = newDirections;}
    void setIsAmazonSeller(string newIsAmazonSeller) {isAmazonSeller = newIsAmazonSeller;}
    void setSizeQuantVar(string newSizeQuantVar) {sizeQuantVar = newSizeQuantVar;}
    void setProductDescription(string newProductDescription) {productDescription = newProductDescription;}

    friend ostream& operator<<(ostream& lhs, Data rhs){
        lhs << "Name: " << rhs.name << endl;
        lhs << "ID: " << rhs.id << endl;
        lhs << "Category: " << rhs.category << endl;
        return lhs;
    }
    Data loadData(string line);
};


std::string cleanedLine(std::stringstream& ss) {
    std::string line;
    std::string tempLine;
    std::string tempLine2;

    getline(ss, line, ',');
    if (!line.empty() && line.front() == '"') {
        line.erase(0, 1);

        while (1) {
            getline(ss, tempLine, '"');
            line += tempLine;
            char next = ss.peek();

            if (next == ',') {
                ss.ignore(1); 
                break;
            }

            getline(ss, tempLine2, ',');
            line += '"' + tempLine2; 
        }
    }

    if (line == ""){line = "NA";}


    return line;
}

Data Data::loadData(string line){
    stringstream ss(line);
    string idLine;
    string nameLine;
    string brandLine;
    string AsinLine;
    List<string> categoryList;
    string categoryLine;
    string categorySegment;
    string upcEanCodeLine;
    string listPriceLine;
    string sellPriceLine;
    string quantityLine;
    string modelNumLine;
    string productInfoLine;
    string productSpecLine;
    string techDetailsLine;
    string shipWeightLine;
    string prodDimensionsLine;
    string imageLine;
    string variantsLine;
    string skuLine;
    string urlLine;
    string stockLine;
    string prodDetailsLine;
    string dimensionLine;
    string colorLine;
    string ingredientsLine;
    string directionsLine;
    string isAmazonSellerLine;
    string sizeQuantVarLine;
    string productDescriptionLine;


    idLine = cleanedLine(ss);
    setId(idLine);
    nameLine = cleanedLine(ss);
    setName(nameLine);
    brandLine = cleanedLine(ss);
    setBrand(brandLine);
    AsinLine = cleanedLine(ss);
    categoryLine = cleanedLine(ss);
    stringstream categoryStream(categoryLine);
    getline(categoryStream, categorySegment, '|');

    while(categorySegment != ""){
        categoryList.insertAtFront(categorySegment);
        getline(categoryStream, categorySegment, '|');
    }

    setAsin(AsinLine);
    upcEanCodeLine = cleanedLine(ss);
    setUpcEanCode(upcEanCodeLine);
    listPriceLine = cleanedLine(ss);
    setListPrice(listPriceLine);
    sellPriceLine = cleanedLine(ss);
    setSellPrice(sellPriceLine);
    quantityLine = cleanedLine(ss);
    setQuantity(quantityLine);
    modelNumLine = cleanedLine(ss);
    setModelNum(modelNumLine);
    productInfoLine = cleanedLine(ss);
    setProductInfo(productInfoLine);
    productSpecLine = cleanedLine(ss);
    setProductSpec(productSpecLine);
    techDetailsLine = cleanedLine(ss);
    setTechDetails(techDetailsLine);
    shipWeightLine = cleanedLine(ss);
    setShipWeight(shipWeightLine);
    prodDimensionsLine = cleanedLine(ss);
    setProdDimensions(prodDimensionsLine);
    imageLine = cleanedLine(ss);
    setImage(imageLine);
    variantsLine = cleanedLine(ss);
    setVariants(variantsLine);
    skuLine = cleanedLine(ss);
    setSku(skuLine);
    urlLine = cleanedLine(ss);
    setUrl(urlLine);
    stockLine = cleanedLine(ss);
    setStock(stockLine);
    prodDetailsLine = cleanedLine(ss);
    setProdDetails(prodDetailsLine);
    dimensionLine = cleanedLine(ss);
    setDimension(dimensionLine);
    colorLine = cleanedLine(ss);
    setColor(colorLine);
    ingredientsLine = cleanedLine(ss);
    setIngredients(ingredientsLine);
    directionsLine = cleanedLine(ss);
    setDirections(directionsLine);
    isAmazonSellerLine = cleanedLine(ss);
    setIsAmazonSeller(isAmazonSellerLine);
    sizeQuantVarLine = cleanedLine(ss);
    setSizeQuantVar(sizeQuantVarLine);
    productDescriptionLine = cleanedLine(ss);
    setProductDescription(productDescriptionLine);
    return *this;

}


